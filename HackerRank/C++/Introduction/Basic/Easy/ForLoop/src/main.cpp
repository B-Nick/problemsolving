#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    // Complete the code.
    static const std::vector<std::string> words = {
        "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    static const int N = 9;

    int a, b;
    std::cin >> a >> b;

    /*getline(cin, n_temp);
    int a = stoi(n_temp);
    getline(cin, n_temp);
    int b = stoi(n_temp);*/

    if (a < 1 || b < 1) throw std::logic_error("Invalid input");

    for (int i = a; i <= b; ++i)
    {
        if (i <= N)
        {
            std::cout << words.at(i - 1) << std::endl;
        }
        else if (i % 2)
        {
            std::cout << "odd" << std::endl;
        }
        else
        {
            std::cout << "even" << std::endl;
        }
    }

    return 0;
}

