#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    enum QueryType {ADD = 1, ERASE = 2, PRINT = 3};
    int q;
    std::cin >> q;
    if (q < 1 || q > 100000)
    {
        std::cerr << "Invalid query count" << std::endl;
        return -1;
    }

    std::map<std::string, int> studentMarksMap;
    while (q--)
    {
        std::string x;
        int type;
        std::cin >> type >> x;

        if (type < ADD || type > PRINT)
        {
            std::cerr << "Invalid query type" << std::endl;
            return -2;
        }
        if (x.empty() || x.size() > 6)
        {
            std::cerr << "Invalid name" << std::endl;
            return -3;
        }
        switch (type)
        {
        case ADD:
        {
            int y;
            std::cin >> y;
            if (y < 1|| y > 1000)
            {
                std::cerr << "Invalid mark" << std::endl;
                return -3;
            }
            if (studentMarksMap.find(x) == studentMarksMap.cend())
            {
                studentMarksMap.insert({x, y});
            }
            else
            {
                studentMarksMap[x] += y;
            }
            break;
        }
        case ERASE:
            studentMarksMap.erase(x);
            break;
        case PRINT:
        {
            const auto record(studentMarksMap.find(x));
            std::cout << (record == studentMarksMap.cend() ? 0 : record -> second) << std::endl;
            break;
        }
        default:
            std::cerr << "Invalid query type" << std::endl;
            return -4;
        }
    }
    return 0;
}



