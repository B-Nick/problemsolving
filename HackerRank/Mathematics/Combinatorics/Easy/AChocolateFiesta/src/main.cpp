#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */





int modPow2(int p)
{
    static const int MOD = 1000000007;

    long result {1l};
    while (p--)
    {
        result = (result << 1) % MOD;
    }
    return static_cast<int>(result);
}


int solve(std::vector<int> a)
{
    if (a.empty() || a.size() > 100000)
    {
        throw std::invalid_argument("Invalid array size");
    }

    const int n {static_cast<int>(a.size())};
    int oddCount {0};
    for (const int e : a)
    {
        if (e & 1) ++oddCount;
    }

    return oddCount > 0 ? modPow2(n - 1) - 1 : modPow2(n) - 1;
}

#define IN cin
//inputStream

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    ifstream inputStream;
    inputStream.open("../test1.txt");

    string a_count_temp;
    getline(IN, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    string a_temp_temp;
    getline(IN, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = solve(a);

    fout << result << "\n";

    std::cout << result << std::endl;

    inputStream.close();

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

/* Direct solution (long)

namespace
{
const int MOD = 1000000007;
}


int binomialCoeff(int n, int k)
{
    static std::vector<std::vector<int>> binomialCoeffs = {{1}, {1, 1}};

    int nc = binomialCoeffs.size() - 1;
    if (nc < n)
    {
        while (nc++ < n)
        {
            binomialCoeffs.push_back({1});
            for (int i = 1; i < nc; ++i)
            {
                binomialCoeffs[nc].push_back((static_cast<long>(binomialCoeffs.at(nc - 1).at(i - 1))
                                              + binomialCoeffs.at(nc - 1).at(i)) % MOD);
            }
            binomialCoeffs[nc].push_back(1);
        }
    }

    assert(n <= nc);

    return binomialCoeffs.at(n).at(k);
}

int modPow(int base, int p)
{
    long result {1l};
    while (p)
    {
        if (p & 1) result = (result * base) % MOD;
        base = (static_cast<long>(base) * base) % MOD;
        p >>= 1;
    }
    return static_cast<int>(result);
}


int solve(std::vector<int> a)
{
    if (a.empty() || a.size() > 100000)
    {
        throw std::invalid_argument("Invalid array size");
    }

    const int n {static_cast<int>(a.size())};
    int evenCount {0};
    for (const int e : a)
    {
        if (!(e & 1)) ++evenCount;
    }
    const int oddCount {n - evenCount};

    const int x {modPow(2, evenCount) - 1};
    // const int y {(modPow(2, oddCount - 1)) - 1};
    int y {0};
    for (int i = 2; i <= oddCount; i += 2)
    {
        const int currBinomCoeff {binomialCoeff(oddCount, i)};
        y = static_cast<int>((static_cast<long>(y) + currBinomCoeff) % MOD);
    }
    const int xy = static_cast<int>((static_cast<long>(x) * y) % MOD);
    return static_cast<int>((static_cast<long>(x) + xy + y) % MOD);

    return modPow2(n - 1) - 1;
}
*/


