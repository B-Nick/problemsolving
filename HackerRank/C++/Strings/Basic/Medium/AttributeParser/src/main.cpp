#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cassert>
#include <stack>
using namespace std;

static const std::string::value_type TAG_START = '<';
static const std::string::value_type TAG_FINISH = '>';
static const std::string::value_type CLOSING_TAG_MARK = '/';
static const int CLOSING_TAG_MARK_POS = 1;
static const char *const WHITESPACES = " \t\n\r\f\v";

struct Node final
{
    std::string tagName;
    std::map<std::string, std::string> attrs;
    std::map<std::string, Node*> childElements;
};

inline std::string &ltrim(std::string &s, const char *const t = WHITESPACES)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

inline std::string &rtrim(std::string &s, const char *const t = WHITESPACES)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

inline std::string &trim(std::string &s, const char *const t = WHITESPACES)
{
    return ltrim(rtrim(s, t), t);
}

inline bool isOpening(const std::string &str)
{
    return str.length() > 2 && str.at(0) == TAG_START &&
           str.at(CLOSING_TAG_MARK_POS) != CLOSING_TAG_MARK &&
           str.at(str.size() - 1) == TAG_FINISH;
}

inline bool isClosing(const std::string &str)
{
    return str.length() > 3 && str.at(0) == TAG_START &&
           str.at(CLOSING_TAG_MARK_POS) == CLOSING_TAG_MARK &&
           str.at(str.size() - 1) == TAG_FINISH;
}

std::string getOpeningTagName(const std::string &element)
{
    std::string::size_type foundPos = element.find_first_of(WHITESPACES, 1);
    if (foundPos == std::string::npos)  // no attributes
    {
        return element.substr(1, element.size() - 2);
    }
    return element.substr(1, foundPos - 1);
}

void parseAtributes(const std::string &element, const int startPos, Node *const pNode)
{
    static const std::string::value_type keyValDelimiter('=');
    static const std::string::value_type valueMark('\"');

    assert(pNode);

    std::string::size_type pos = startPos;

    while (true)
    {
        pos = element.find_first_not_of(WHITESPACES, pos);
        if (pos == std::string::npos)
        {
            throw std::logic_error("Invalid HRML");
        }
        if (element.at(pos) == TAG_FINISH)  // no attributes
        {
            return;
        }

        std::string::size_type foundPos = element.find(keyValDelimiter, pos);
        if (foundPos == pos)
        {
            throw std::logic_error("No attribute name");
        }
        if (foundPos == std::string::npos)
        {
            throw std::logic_error("Attribute without value");
        }
        std::string currAttr(element.substr(pos, (foundPos - pos)));
        trim(currAttr);

        // looking for a string inside ""
        pos = element.find(valueMark, foundPos + 1);
        if (pos == std::string::npos)
        {
            throw std::logic_error("Attribute without value");
        }
        ++pos;
        foundPos = element.find(valueMark, pos);
        std::string currVal(element.substr(pos, (foundPos - pos)));
        trim(currVal);

        pNode -> attrs[currAttr] = currVal;

        pos = foundPos + 1;
    }
}

std::string getClosingTagName(const std::string &element)
{
    static const std::string tagDelimiters(WHITESPACES);
    std::string::size_type foundPos = element.find_first_of(tagDelimiters, 2);
    if (foundPos == std::string::npos)  // no attributes
    {
        return element.substr(2, element.size() - 3);
    }
    return element.substr(2, foundPos - 2);
}

Node *parseOpeningElement(const std::string &element, Node *const pParent)
{
    assert(pParent);

    const std::string tagName(getOpeningTagName(element));
    Node *pChild = nullptr;
    if (pParent -> childElements.count(tagName))
    {
        pChild = pParent -> childElements.at(tagName);
    }
    else
    {
        pChild = new Node;
        pChild -> tagName = tagName;
    }

    assert(pChild);

    parseAtributes(element, tagName.length() + 1, pChild);

    pParent -> childElements.insert({tagName, pChild});

    return pChild;
}

// result[result.size() - 1] is attr name
std::vector<std::string> parseQuery(const std::string &q)
{
    static const std::string::value_type tagDelimiter('.');
    static const std::string::value_type attrDelimiter('~');

    std::vector<std::string> queryComponents;
    std::string::size_type pos {0};

    while (true)
    {
        std::string::size_type foundPos = q.find(tagDelimiter, pos);
        if (foundPos == pos)
        {
            throw std::logic_error("Invalid query: empty tag");
        }
        if (foundPos == std::string::npos)
        {
            foundPos = q.find(attrDelimiter, pos);
            if (foundPos == pos)
            {
                throw std::logic_error("Invalid query: empty tag");
            }
            if (foundPos == std::string::npos)
            {
                throw std::logic_error("Invalid query: no attribute");
            }
            queryComponents.push_back(q.substr(pos, (foundPos - pos)));
            queryComponents.push_back(q.substr(foundPos + 1));
            break;
        }
        queryComponents.push_back(q.substr(pos, (foundPos - pos)));
        pos = foundPos + 1;
    }

    if (queryComponents.empty())
    {
        throw std::logic_error("Invalid query: no tags");
    }
    return queryComponents;
}

std::string processParsedQuery(const std::vector<std::string> &parsedQuery, const Node *const pRootNode)
{
    static const std::string NOT_FOUND {"Not Found!"};

    assert(pRootNode);

    if (parsedQuery.empty())
    {
        throw std::invalid_argument("Empty query");
    }

    const std::vector<int>::size_type n = parsedQuery.size();
    const Node *currNode = pRootNode;
    for (std::vector<int>::size_type i = 0; i < n - 1; ++i)
    {
        if (currNode -> childElements.count(parsedQuery.at(i)))
        {
            currNode = currNode -> childElements.at(parsedQuery.at(i));
        }
        else
        {
            return NOT_FOUND;
        }
    }
    return currNode -> attrs.count(parsedQuery.at(n - 1)) ?
               currNode -> attrs.at(parsedQuery.at(n - 1)) :
               NOT_FOUND;
}

// Does NOT make ptr to removed node null!
void removeNode(Node *const pNode)
{
    for (const auto & nodePair : pNode -> childElements)
    {
        Node *const childNode = nodePair.second;

        assert(childNode);

        removeNode(childNode);
    }
    delete pNode;
}

int main() {


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    std::cin >> N >> Q;
    if (N < 1 || N > 20)
    {
        std::cerr << "Invalid N" << std::endl;
        return -1;
    }
    if (Q < 1 || Q > 20)
    {
        std::cerr << "Invalid Q" << std::endl;
        return -2;
    }
    std::cin.get();

    std::stack<Node*> nodeStack;
    Node *const pRoot = new Node; // never has attributes, only children
    nodeStack.push(pRoot);

    Node *currNode = nodeStack.top();
    nodeStack.pop();
    while (N--)
    {
        std::string line;
        if (!std::getline(std::cin, line))
        {
            std::cerr << "No more input" << std::endl;
            return -3;
        }
        if (line.empty())
        {
            std::cerr << "Invalid HRML: empty line" << std::endl;
            return -4;
        }
        if (isOpening(line))
        {
            Node *const newChild = parseOpeningElement(line, currNode);
            nodeStack.push(currNode);
            currNode = newChild;

        }
        else if (isClosing(line))
        {
            const std::string currClosingTagName(getClosingTagName(line));
            if (currClosingTagName != currNode -> tagName)
            {
                std::cerr << "Invalid HRML: tag mismatch" << std::endl;
                return -5;
            }
            if (nodeStack.empty())
            {
                std::cerr << "Invalid HRML: unexpected closing tag" << std::endl;
                return -6;
            }
            currNode = nodeStack.top();
            nodeStack.pop();
        }
    }

    while (Q--)
    {
        std::string qLine;
        if (!std::getline(std::cin, qLine))
        {
            std::cerr << "No more input" << std::endl;
            return -7;
        }
        if (qLine.empty())
        {
            std::cerr << "Invalid query: empty line" << std::endl;
            return -8;
        }
        trim(qLine);
        std::cout << processParsedQuery(parseQuery(qLine), pRoot) << std::endl;
    }

    removeNode(pRoot);
    // pRoot isn't null here



    /*Node *currNode = nodeStack.top();
    nodeStack.pop();

    Node *newChild = new Node;
    currNode -> childElements.insert({"tag0", newChild});
    nodeStack.push(currNode);
    currNode = newChild;
    currNode -> attrs.insert({"attr00", "val00"});
    currNode -> attrs.insert({"attr01", "val01"});

    currNode = nodeStack.top();
    nodeStack.pop();

    newChild = new Node;
    currNode -> childElements.insert({"tag1", newChild});
    nodeStack.push(currNode);
    currNode = newChild;
    currNode -> attrs.insert({"attr10", "val10"});
    currNode -> attrs.insert({"attr11", "val11"});

    newChild = new Node;
    currNode -> childElements.insert({"tag2", newChild});
    nodeStack.push(currNode);
    currNode = newChild;
    currNode -> attrs.insert({"attr20", "val20"});
    currNode -> attrs.insert({"attr21", "val21"});

    nodeStack.pop();
    nodeStack.pop();

    std::cout << pRoot -> childElements.at("tag0") -> attrs.at("attr00") << std::endl;

    std::string q0("tag1.tag2.tag3~attr20");

    std::cout << processParsedQuery(parseQuery(q0), pRoot) << std::endl;

    std::cout << processParsedQuery(parseQuery("tag1.tag2~attr20"), pRoot) << std::endl;*/

    return 0;
}

