#include <iostream>
using namespace std;

#define ITERATIVE

// Enter your code for reversed_binary_value<bool...>()
#ifdef RECURSIVE
template <bool d>
int reversed_binary_value()
{
    return d;
}

template <bool d0, bool d1, bool... digits>
int reversed_binary_value()
{
    const int r = reversed_binary_value<d1, digits...>();
    return (r << 1) + d0;
}
#endif // RECURSIVE

#ifdef ITERATIVE
template <bool... digits>
int reversed_binary_value()
{
    int result = 0;
    int ord = 1;
    for (const bool digit : {digits...})
    {
        result += static_cast<int>(digit) * ord;
        ord <<= 1;
    }
    return result;
}
#endif // ITERATIVE

template <int n, bool... digits>
struct CheckValues {
    static void check(int x, int y)
    {
        CheckValues<n-1, 0, digits...>::check(x, y);
        CheckValues<n-1, 1, digits...>::check(x, y);
    }
};

template <bool...digits>
struct CheckValues<0, digits...> {
    static void check(int x, int y)
    {
        int z = reversed_binary_value<digits...>();
        std::cout << (z+64*y==x);
    }
};

int main()
{
    int t; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}
