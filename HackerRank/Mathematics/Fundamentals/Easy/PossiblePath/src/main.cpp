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
 *  1. LONG_INTEGER a
 *  2. LONG_INTEGER b
 *  3. LONG_INTEGER x
 *  4. LONG_INTEGER y
 */



// Reduce coordinates to the lowest absolute values
// using provided operation; for a > b:
// (a - b, b) -> (a - b - b, b) -> ... -> (a % b, b) -> ... -> (a % b, b % (a % b)) -> ... ->
// -> (f, 0), f is GCD(a, b)
/*
std::pair<long, long> reduce(long c, long d)
{
    assert(c >= d);

    while (c && d)
    {
        if (c >= d)
        {
            const long tmp {d};
            d = c % d;
            c = tmp;
        }
        else
        {
            const long tmp {c};
            c = d % c;
            d = tmp;
        }

    }
    return {c, d};
}
*/

long gcd(long c, long d)
{
    assert(c >= d);

    while (d)
    {
        const long tmp {d};
        d = c % d;
        c = tmp;

    }
    return c;
}

std::string solve(long a, long b, long x, long y)
{
    static const long M {1000000000000000000l};
    static std::string YES {"YES"};
    static std::string NO {"NO"};

    if (a < 1 || b < 1 || x < 1 || y < 1 ||
        a > M || b > M || x > M || y > M)
    {
        throw std::invalid_argument("Invalid input arguments");
    }


    // if reduced coordinates are the same then points are reacheable
    /*const auto reduced0 = a > b ? reduce(a, b) : reduce(b, a);
    const auto reduced1 = x > y ? reduce(x, y) : reduce(y, x);

    return reduced0 == reduced1 ? YES : NO;*/

    const auto gcd0 = a > b ? gcd(a, b) : gcd(b, a);
    const auto gcd1 = x > y ? gcd(x, y) : gcd(y, x);

    return gcd0 == gcd1 ? YES : NO;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        long a = stol(first_multiple_input[0]);

        long b = stol(first_multiple_input[1]);

        long x = stol(first_multiple_input[2]);

        long y = stol(first_multiple_input[3]);

        std::string result = solve(a, b, x, y);

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
