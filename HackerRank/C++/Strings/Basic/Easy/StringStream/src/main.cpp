#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

std::vector<int> parseInts(std::string str)
{
    if (str.empty() || str.size() > 800000) throw std::invalid_argument("Invalid string length");

    std::stringstream sstream(str);

    std::vector<int> result;
    int number;
    char delimiter;
    while (sstream >> number)
    {
        sstream >> delimiter;
        result.push_back(number);
    }
    return result;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}
