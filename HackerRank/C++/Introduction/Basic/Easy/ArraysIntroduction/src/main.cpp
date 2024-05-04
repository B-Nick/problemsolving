#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    std::cin >> n;
    if (n < 1 || n > 1000) throw std::logic_error("Invalid length");
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
