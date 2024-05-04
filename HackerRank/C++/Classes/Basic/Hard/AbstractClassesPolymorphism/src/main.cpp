#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache final : public Cache
{

public:
    explicit LRUCache(const int c)
        : Cache()
    {
        if (c < 1 || c > 1000) throw std::invalid_argument("Invalid capacity");

        Cache::cp = c;
        tail = nullptr;
        head = nullptr;
    }

    LRUCache(const LRUCache &other) = delete;
    LRUCache(LRUCache &&other) = default;

    // virtual ~LRUCache() final = default;

    LRUCache &operator= (const LRUCache &other) = delete;
    LRUCache &operator= (LRUCache &&other) = default;

    virtual void set(int k, int v) override final
    {
        if (k < 1 || k > 20) throw std::invalid_argument("Invalid key");
        if (v < 1 || v > 2000) throw std::invalid_argument("Invalid value");

        if (mp.count(k))
        {
            Node *const foundNode = mp.at(k);
            foundNode -> value = v;
            /*if (foundNode != tail)  // (*)
            {
                if (foundNode -> prev)
                {
                    foundNode -> prev -> next = foundNode -> next;
                }

                assert(foundNode -> next); // due to (*)

                foundNode -> next -> prev = foundNode -> prev;

                tail -> prev = foundNode;
                foundNode -> next = tail;
                foundNode -> prev = nullptr;
                tail = foundNode;
            }*/
        }
        else    // if (mp.count(k))
        {
            if (mp.size() >= static_cast<decltype(mp.size())>(cp))
            {
                Node *const newHead = head -> prev;
                if (newHead) newHead -> next = nullptr;
                mp.erase(head -> key);
                delete head;
                head = newHead;
                if (!head) tail = nullptr;
            }

            Node *const newNode = new Node(k, v);

            newNode -> next = tail;
            newNode -> prev = nullptr;
            if (tail)
            {
                tail -> prev = newNode;
            }
            tail = newNode;
            if (!head) head = tail; // empty
            mp.insert({k, newNode});
        }
    }

    virtual int get(int k) override final
    {
        if (mp.count(k))
        {
            Node *const foundNode = mp.at(k);

            assert(tail);

            if (foundNode != tail)  // (*)
            {
                if (foundNode -> next)
                {
                    foundNode -> next -> prev = foundNode -> prev;
                }

                assert (foundNode -> prev); // due to (*)

                foundNode -> prev -> next = foundNode -> next;

                tail -> prev = foundNode;
                foundNode -> next = tail;
                foundNode -> prev = nullptr;
                tail = foundNode;
            }
            return foundNode -> value;
        }
        return -1;
    }

};

int main() {
    int n, capacity,i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
        string command;
        cin >> command;
        if(command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
    }
    return 0;
}
