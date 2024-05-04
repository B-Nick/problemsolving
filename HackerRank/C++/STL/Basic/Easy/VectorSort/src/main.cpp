#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    std::cin >> n;
    if (n < 1 || n > 100000)
    {
        std::cerr << "Invalid n" << std::endl;
        return -1;
    }

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        int e;
        std::cin >> e;
        if (e < 1 || e > 1000000000)
        {
            std::cerr << "Invalid element" << std::endl;
            return -2;
        }
        v[i] = e;
    }

    std::sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
    {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
