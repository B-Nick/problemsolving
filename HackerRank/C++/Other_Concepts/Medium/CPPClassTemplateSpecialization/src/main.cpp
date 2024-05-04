#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template <> struct Traits<Fruit>
{
    static std::string name(const int index)
    {
        if (index < -2000000000 || index > 2000000000)
        {
            throw std::invalid_argument("Invalid index");
        }

        switch (index)
        {
        case static_cast<int>(Fruit::apple):
            return "apple";
        case static_cast<int>(Fruit::orange):
            return "orange";
        case static_cast<int>(Fruit::pear):
            return "pear";
        default:
            return "unknown";
        }
        return "unknown";
    }
};

template <> struct Traits<Color>
{
    static std::string name(const int index)
    {
        if (index < -2000000000 || index > 2000000000)
        {
            throw std::invalid_argument("Invalid index");
        }

        switch (index)
        {
        case static_cast<int>(Color::red):
            return "red";
        case static_cast<int>(Color::green):
            return "green";
        case static_cast<int>(Color::orange):
            return "orange";
        default:
            return "unknown";
        }
        return "unknown";
    }
};


int main()
{
    int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
