#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    static const std::string YES = "Yes";
    static const std::string NO = "No";

    int n;
    std::cin >> n;
    if (n < 1 || n > 100000)
    {
        std::cerr << "Invalid n" << std::endl;
        return -1;
    }

    std::vector<int> v(n);
    int prev = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i)
    {
        int e;
        std::cin >> e;
        if (e < 1 || 1000000000 < e)
        {
            std::cerr << "Invalid element" << std::endl;
            return -2;
        }
        if (e < prev)
        {
            std::cerr << "Unsorted" << std::endl;
            return -3;
        }
        v[i] = e;
    }

    int q;
    std::cin >> q;
    if (q < 1 || q > 100000)
    {
        std::cerr << "Invalid quiery count" << std::endl;
        return -4;
    }

    while (q--)
    {
        int y;
        std::cin >> y;
        if (y < 1 || 1000000000 < y)
        {
            std::cerr << "Invalid quiery" << std::endl;
            return -5;
        }

        std::vector<int>::const_iterator lb = std::lower_bound(v.cbegin(), v.cend(), y);
        if (lb == v.cend())
        {
            std::cerr << "No lower bound" << std::endl;
            return -6;
        }
        const int nN = std::distance(v.cbegin(), lb) + 1;
        std::cout << (*lb == y ? YES : NO);
        std::cout << " " << nN << std::endl;
    }
    return 0;
}
