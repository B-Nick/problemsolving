#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 *  3. INTEGER c
 */

#define MATH

#ifdef SIM
// Simulation (brute force) approach
std::string solve(int a, int b, int c)
{
    static const std::string YES("YES");
    static const std::string NO("NO");

    if (a < 1 || a > 1000) throw std::invalid_argument("Invalid a");
    if (b < 1 || b > 1000) throw std::invalid_argument("Invalid b");
    if (c < 1 || c > 1000) throw std::invalid_argument("Invalid c");

    const int mx = std::max(a, b);
    const int mn = std::min(a, b);

    if (c > mx) return NO;

    std::vector<bool> visited(mx, false);
    int currMx = mx - mn;

    while (true)
    {
        while (mn - currMx >= 0)
        {
            currMx = mx - (mn - currMx);
            if (visited[currMx]) return NO;
            visited[currMx] = true;
            std::cout << currMx << std::endl;

            if (!(c % currMx)) return YES;
        }
        currMx -= mn;
        if (visited[currMx]) return NO;;
        std::cout << currMx << std::endl;
        visited[currMx] = true;

        if (!(c % currMx)) return YES;
    }
    return NO;
}
#elif defined MATH
int gcd(int a, int b)
{
    assert(a >= b);

    if (a == b || !b) return a;
    return gcd(b, a % b);
}

// Math approach
std::string solve(int a, int b, int c)
{
    static const std::string YES("YES");
    static const std::string NO("NO");

    if (a < 1 || a > 1000) throw std::invalid_argument("Invalid a");
    if (b < 1 || b > 1000) throw std::invalid_argument("Invalid b");
    if (c < 1 || c > 1000) throw std::invalid_argument("Invalid c");

    if (c > a && c > b) return NO;

    const int abGCD = gcd(std::max(a, b), std::min(a, b));

    return c % abGCD ? NO : YES;
}
#endif // SIM / MATH

/*
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

    int sqrtN = std::sqrt(n);
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

// if both jugs doesn't have prime factors in common
// there's a sequence for any value c: 1..a+b
std::string solve(int a, int b, int c)
{
    static const std::string YES("YES");
    static const std::string NO("NO");

    if (a < 1 || a > 1000) throw std::invalid_argument("Invalid a");
    if (b < 1 || b > 1000) throw std::invalid_argument("Invalid b");
    if (c < 1 || c > 1000) throw std::invalid_argument("Invalid c");

    std::map<int, int> factorDegreesA = primeFactorization(a);
    std::map<int, int> factorDegreesB = primeFactorization(b);
    for (const auto &cfda : factorDegreesA)
    {
        if (factorDegreesB.count(cfda.first)) return NO;
    }
    return c <= a + b ? YES : NO;
}*/



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp );

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int a = stoi(first_multiple_input[0]);

        int b = stoi(first_multiple_input[1]);

        int c = stoi(first_multiple_input[2]);

        string result = solve(a, b, c);

        fout << result << "\n";

        std::cout << result << std::endl;
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
