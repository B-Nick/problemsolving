#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

std::string solve(long n)
{
    static const std::string SUCCESS {"Go On Bob"};
    static const std::string FAIL {"Better Luck Next Time"};

    if (n < 1l || n > 1000000000000000000l)
    {
        throw std::invalid_argument("Invalid boxes count");
    }

    // box(n) = SUM[i = 1..n](i) = n*(n + 1) / 2
    // (arithmetic progression, a[1] = 1, d = 1)
    // n is the number of moves, box(n) is box number after n moves
    // => Square equation: n * n + n - 2 * box(n) = 0
    // must have positive integer roots
    // D = 1 + 4 * 2 * box(n) must be an integer such that
    // sqrt(D) - 1 is even
    // (sqrt(D) - 1) / 2 is the number of moves
    // 2^63 ~= 9e18, 4 * 2 * 1e18 = 8e18 must fit in long

    const long d {1 + (n << 3)};
    const long sqrtd {static_cast<long>(sqrt(d) + std::numeric_limits<double>::epsilon())};
    if (d != sqrtd * sqrtd || (sqrtd - 1) & 1) return FAIL;

    return SUCCESS + " " + std::to_string((sqrtd - 1) >> 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        std::string result = solve(n);

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
