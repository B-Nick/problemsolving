#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/
template <typename T>
class AddElements final
{
public:
    explicit AddElements(const T &el)
        : m_el{el} {}
    const T &add(const T &el)
    {
        m_el += el;
        return m_el;
    }

private:
    T m_el {};
};

template <>
class AddElements<std::string> final
{
public:
    explicit AddElements(const std::string &el)
        : m_el{el} {}
    const std::string add(const std::string &el)
    {
        return concatenate(el);
    }
    const std::string &concatenate(const std::string &el)
    {
        return m_el.append(el);
    }

private:
    std::string m_el;
};

int main () {
    int n,i;
    cin >> n;
    for(i=0;i<n;i++) {
        string type;
        cin >> type;
        if(type=="float") {
            double element1,element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat (element1);
            cout << myfloat.add(element2) << endl;
        }
        else if(type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint (element1);
            cout << myint.add(element2) << endl;
        }
        else if(type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring (element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
