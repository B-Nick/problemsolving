#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    std::cin >> n >> q;

    if (n < 1 || n > 100000)
    {
        std::cerr << "Invalid n" << std::endl;
        return -1;
    }
    if (q < 1 || q > 100000)
    {
        std::cerr << "Invalid q" << std::endl;
        return -2;
    }

    std::vector<std::vector<int>*> a(n);

    int kSum = 0;
    for (int i = 0; i < n; ++i)
    {
        int k;
        std::cin >> k;
        if (k < 1 || k > 300000)
        {
            std::cerr << "Invalid k" << std::endl;
            return -3;
        }
        kSum += k;
        if (kSum > 300000)
        {
            std::cerr << "Invalid k" << std::endl;
            return -4;
        }
        a[i] = new std::vector<int>(k);
        for (int j = 0; j < k; ++j)
        {
            int v;
            std::cin >> v;
            if (v < 0 || v > 1000000)
            {
                std::cerr << "Invalid integer value" << std::endl;
                return -5;
            }
            (*a[i])[j] = v;
        }

    }
    if (kSum < n)
    {
        std::cerr << "Invalid k" << std::endl;
        return -4;
    }
    while (q--)
    {
        int i, j;
        std::cin >> i >> j;
        if (i < 0 || i >= n)
        {
            std::cerr << "Invalid i" << std::endl;
            return -6;
        }
        const int k = a.at(i) -> size();
        if (j < 0 || j >= k)
        {
            std::cerr << "Invalid j" << std::endl;
            return -7;
        }
        std::cout << a.at(i) -> at(j) << std::endl;
    }

    /* const int nn = variableSizedArrays.size();
    std::cout << "n " << nn << std::endl;
    for (int i = 0; i < nn; ++i)
    {
        const int kk = variableSizedArrays.at(i) -> size();
        std::cout << "k[" << i << "] " << kk << ": ";
        for (int j = 0; j < kk; ++j)
        {
            std::cout << variableSizedArrays[i] -> at(j) << " ";
        }
        std::cout << std::endl;
    }*/


    for (int i = 0; i < n; ++i)
    {
        delete a[i];
    }
    return 0;
}
