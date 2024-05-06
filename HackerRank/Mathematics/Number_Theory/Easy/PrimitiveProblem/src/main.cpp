#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

std::map<int, int> primeFactorization(int n)
{
    std::map<int, int> factorDegrees;
    if (!(n & 1))
    {
        factorDegrees.insert({2, 0});
    }
    while (n > 1 && !(n & 1))
    {
        ++factorDegrees[2];
        n >>= 1;
    }

    int sqrtN {static_cast<int>(std::sqrt(n))};
    for (int i = 3; i <= sqrtN; i += 2)
    {
        const int n0 = n;
        while (!(n % i))
        {
            if (!factorDegrees.count(i))
            {
                factorDegrees.insert({i, 0});
            }
            ++factorDegrees[i];
            n = n / i;
        }
        if (n0 != n) sqrtN = std::sqrt(n);
    }
    if (n > 2)
    {
        factorDegrees.insert({n, 1});
    }
    return factorDegrees;
}

int modPow(int base, int pwr, const int mod)
{
    long result {1l};
    while (pwr)
    {
        if (pwr & 1) result = static_cast<int>((result * base) % mod);
        base = static_cast<int>((static_cast<long>(base) * base) % mod);
        pwr >>= 1;
    }
    return static_cast<int>(result);
}

int gcd(int a, int b)
{
    if (b > a) std::swap(a, b);
    while (b)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}



int main()
{
    string p_temp;
    getline(cin, p_temp);
    int p = stoi(ltrim(rtrim(p_temp)));

    //int p = 35382307;
    if (p <= 2 || p >= 1000000000)
    {
        std::cerr << "Invalid number" << std::endl;
        return 1;
    }


    std::map<int, int> primeFactorsPM1 {primeFactorization(p - 1)};
    std::vector<int> powers;
    for (const auto &pf : primeFactorsPM1)
    {
        powers.push_back((p - 1) / pf.first);
    }

    int smallestPrimitiveRoot {-1};
    for (int i = 2; i < p; ++i)
    {
        bool foundOne {false};
        for (const int pwr :  powers)
        {
            const int currPwrMod = modPow(i, pwr, p);
            if (currPwrMod == 1)
            {
                foundOne = true;
                break;
            }
        }
        if (!foundOne)
        {
            smallestPrimitiveRoot = i;
            break;
        }
    }
    if (smallestPrimitiveRoot < 2)
    {
        std::cerr << "Error" << std::endl;
        return 2;
    }

    // Using the Euler's product formula
    double result = p;
    for (const auto &pf : primeFactorsPM1)
    {
        result *= (1.0 - 1.0 / pf.first);
    }

    /* Brute force find Euler's totient function
    int counter {1};
    for (int i = 2; i < p - 1; ++i)
    {
        if (gcd(p - 1, i) == 1)
        {
            ++counter;
        }
    }*/
    std::cout << smallestPrimitiveRoot << " " << static_cast<int>(result) << std::endl;

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
        );

    return s;
}
