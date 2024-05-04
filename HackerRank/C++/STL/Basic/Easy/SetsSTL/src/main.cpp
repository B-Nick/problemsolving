#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    static const std::string YES = "Yes";
    static const std::string NO = "No";
    enum QueryType {ADD = 1, DELETE = 2, CHECK = 3};

    int q;
    std::cin >> q;
    if (q < 1 || q > 100000)
    {
        std::cerr << "Invalid query count" << std::endl;
        return -1;
    }

    std::set<int> currSet;
    while (q--)
    {
        int y, x;
        std::cin >> y >> x;
        if (y < ADD || y > CHECK)
        {
            std::cerr << "Invalid query type" << std::endl;
            return -2;
        }
        if (x < 1|| x > 1000000000)
        {
            std::cerr << "Invalid query arg" << std::endl;
            return -3;
        }

        switch (y)
        {
        case ADD:
            currSet.insert(x);
            break;
        case DELETE:
            currSet.erase(x);
            break;
        case CHECK:
            std::cout << (currSet.find(x) == currSet.cend() ? NO : YES) << std::endl;
            break;
        default:
            std::cerr << "Invalid query type" << std::endl;
            return -4;
        }
    }

    return 0;
}



