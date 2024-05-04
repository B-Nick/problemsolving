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
        v[i] = e;
    }

    int x;
    std::cin >> x;
    if (x < 1 || x > n)
    {
        std::cerr << "Invalid x" << std::endl;
        return -2;
    }
    v.erase(v.begin() + x - 1);

    n = v.size();
    int a, b;
    std::cin >> a >> b;
    if (a < 1 || b <= a || n < b)
    {
        std::cerr << "Invalid a or b" << std::endl;
        return -3;
    }
    v.erase(v.begin() + a - 1, v.begin() + b - 1);

    n = v.size();
    std::cout << n << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << v.at(i) << " ";
    }
    std::cout << std::endl;


    return 0;
}
