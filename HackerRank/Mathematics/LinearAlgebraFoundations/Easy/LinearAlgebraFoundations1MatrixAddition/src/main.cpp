#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    static const int n {3};

    std::vector<std::vector<int>> matrix1 = {
        {1, 2, 3},
        {2, 3, 4},
        {1, 1, 1}
    };
    std::vector<std::vector<int>> matrix2 = {
        {4, 5, 6},
        {7, 8, 9},
        {4, 5, 7}
    };


    std::vector<std::vector<int>> result(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << result[i][j] << std::endl;
        }
    }

    return 0;
}
