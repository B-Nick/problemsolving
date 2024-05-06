#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

std::unordered_map<int, int> primeFactorization(int n)
{
    assert(n > 0);

    std::unordered_map<int, int> result;
    while (n > 1 && !(n & 1))
    {
        if (!result.count(2))
        {
            result[2] = 1;
        }
        else
        {
            ++result[2];
        }
        n >>= 1;
    }
    int currSqrtN {static_cast<int>(std::sqrt(n))};
    for (int i = 3; i <= currSqrtN; i += 2)
    {
        const int prevN = n;
        while (n > 1 && !(n % i))
        {
            if (!result.count(i))
            {
                result[i] = 1;
            }
            else
            {
                ++result[i];
            }
            n /= i;
        }
        if (prevN != n) currSqrtN = static_cast<int>(std::sqrt(n));
    }
    if (n > 2)
    {
        result[n] = 1;
    }
    return result;
}

int countDigitSum(int n)
{
    int result {0};
    while (n)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int solve(int n)
{
    if (n < 0 || n > 2147483647)
    {
        throw std::invalid_argument("Invalid number");
    }

    const int digitSum {countDigitSum(n)};

    const auto primeFactors {primeFactorization(n)};
    if (primeFactors.size() == 1 &&
        primeFactors.count(n) == 1) // n is prime itself
    {
        return 0;
    }
    int primeSum {0};
    for (const auto f : primeFactors)
    {
        const int currPrimeDigitSum {countDigitSum(f.first)};
        primeSum += currPrimeDigitSum * f.second;
    }

    return digitSum == primeSum ? 1 : 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    int result = solve(n);

    fout << result << "\n";

    std::cout << result << std::endl;

    fout.close();

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
