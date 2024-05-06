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

int getGCD(int x, int y)
{
    if (x < y) std::swap(x, y);
    while (y)
    {
        x = x % y;
        std::swap(x, y);
    }
    return x;
}

#define MAX 10000

// See docs included
// if c <= a < b:
// f{fx + fy}(x) = x/(a * b)
// P(c) = I{0..c}(xdx/(a * b)) = (c^2) / (2 * a * b)
// I is integral
// if a < c <= b:
// f{fx + fy}(x) = 1 / b
// P(c) = I{0..a}(xdx / (a * b)) + I{a..c}(dx / b)
// if a < b <= c:
// f{fx + fy}(x) = (a + b - x) / (a * b)
// P(c) = I{0..a}(xdx / (a * b)) + I{a..b}(dx / b) + I{b..c}((a + b - x)dx / (a * b))

std::string solve(int a, int b, int c)
{
    if (a < 0 || a > MAX)
    {
        throw std::invalid_argument("Invalid a");
    }
    if (b < 0 || b > MAX)
    {
        throw std::invalid_argument("Invalid b");
    }
    if (c < 0 || c > MAX)
    {
        throw std::invalid_argument("Invalid c");
    }
    if (a + b <= c) return "1/1";
    const int p {std::min(a, b)};
    const int q {std::max(a, b)};
    if (c <= p)
    {
        const int n = c * c;
        const int d = (a * b) << 1;
        const int gcd {getGCD(n, d)};
        return std::to_string(n / gcd) + "/" + to_string(d / gcd);
    }
    if (c <= q)
    {
        const int n = (c << 1) - p;
        const int d = q << 1;
        const int gcd {getGCD(n, d)};
        return std::to_string(n / gcd) + "/" + to_string(d / gcd);
    }
    // c > q && c <= p + q == a + b
    const int n = ((p * c) << 1) + ((q * c) << 1) - p * p - q * q - c * c;
    const int d = (p * q) << 1;
    const int gcd {getGCD(n, d)};
    return std::to_string(n / gcd) + "/" + to_string(d / gcd);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    for (int n_itr = 0; n_itr < n; n_itr++) {
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
