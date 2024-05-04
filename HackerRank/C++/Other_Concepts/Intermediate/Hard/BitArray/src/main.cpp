#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    static const unsigned MOD = 1u << 31;

    unsigned n;
    std::cin >> n;
    if (n < 1 || n > 100000000u)
    {
        std::cerr << "Invalid n" << std::endl;
    }

    unsigned s, p, q;

    auto getParam = [](unsigned &x) -> bool
    {
        std::cin >> x;
        return x < MOD;
    };

    if (!getParam(s))
    {
        std::cerr << "Invalid s" << std::endl;
    }
    if (!getParam(p))
    {
        std::cerr << "Invalid p" << std::endl;
    }
    if (!getParam(q))
    {
        std::cerr << "Invalid q" << std::endl;
    }
    // Allocating in heap (doesn't fit to stack in some systems)
    //std::unique_ptr<std::bitset<MOD>> unique(std::make_unique<std::bitset<MOD>>());    // 0 0 ... 0
    std::bitset<MOD> *const unique = new std::bitset<MOD>;    // 0 0 ... 0

    unsigned a = s;
    unique->set(a, true);
    int counter {1};
    for (unsigned i = 1; i < n; ++i)
    {
        a = ((static_cast<unsigned long>(a) * p) % MOD + q) % MOD;
        if (unique->test(a)) break;
        ++counter;
        unique->set(a, true);

    }

    //std::cout << unique->count() << std::endl;

    std::cout << counter << std::endl;

    delete unique;

    return 0;
}


// Brute force
/*unsigned *a = new unsigned[MAX] {0};
    a[0] = s % MOD;
    for (unsigned i = 1; i < n; ++i)
    {
        a[i] = ((static_cast<unsigned long>(a[i - 1]) % MOD * p % MOD) % MOD + q % MOD) % MOD;

        if (a[i] == 8311672) std::cout << "!!!!! " << i << std::endl;

    }

    std::sort(a, a + n);

    std::vector<unsigned> vals;
    unsigned counter {1};
    vals.push_back(a[0]);
    for (unsigned i = 0; i < n - 1; ++i)
    {
        if (a[i] != a[i + 1])
        {
            ++counter;
            vals.push_back(a[i + 1]);
        }
    }

    for (const unsigned e : vals)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << counter << std::endl;

    delete[] a;*/


/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <memory>
using namespace std;


int main()
{

static const unsigned MOD = 1u << 31;

unsigned n;
std::cin >> n;
if (n < 1 || n > 100000000u)
{
    std::cerr << "Invalid n" << std::endl;
}

unsigned s, p, q;

auto getParam = [](unsigned &x) -> bool
{
    std::cin >> x;
    return x < MOD;
};

if (!getParam(s))
{
    std::cerr << "Invalid s" << std::endl;
}
if (!getParam(p))
{
    std::cerr << "Invalid p" << std::endl;
}
if (!getParam(q))
{
    std::cerr << "Invalid q" << std::endl;
}
// Allocating in heap (doesn't fit to stack in some systems)
//std::unique_ptr<std::bitset<MOD>> unique(std::make_unique<std::bitset<MOD>>());    // 0 0 ... 0
std::bitset<MOD> *const unique = new std::bitset<MOD>;    // 0 0 ... 0

unsigned a = s;
unique->set(a, true);
for (unsigned i = 1; i < n; ++i)
{
    a = ((static_cast<unsigned long>(a) * p) % MOD + q) % MOD;
    unique->set(a, true);
}

std::cout << unique->count() << std::endl;

delete unique;

return 0;
}
*/

