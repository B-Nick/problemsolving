#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'closestNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 *  3. INTEGER x
 */

#define BOUND 1000000000

int pow(int a, int b)
{
    long result {1};
    while (b)
    {
        if (b & 1) result *= a;
        a *= a;
        b >>= 1;
    }
    if (result > BOUND)
    {
        throw std::invalid_argument("Too large a^b");
    }
    return static_cast<int>(result);
}

int closestNumber(int a, int b, int x)
{
    if (a < 1 || a > BOUND)
    {
        throw std::invalid_argument("Invalid a");
    }
    if (b < -BOUND || b > BOUND)
    {
        throw std::invalid_argument("Invalid b");
    }
    if (x < 1 || x > BOUND)
    {
        throw std::invalid_argument("Invalid x");
    }

    if (a == 1)
    {
        if (x == 1) return 1;
        return 0;
    }

    if (b < 0) return 0;

    const int apowb {pow(a, b)};
    const int candidate0 {(apowb / x) * x};
    const int candidate1 {((apowb + x) / x) * x};
    const int diff0 {apowb - candidate0};
    const int diff1 {candidate1 - apowb};

    return diff0 <= diff1 ? candidate0 : candidate1;
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

        int a = stoi(first_multiple_input[0]);

        int b = stoi(first_multiple_input[1]);

        int x = stoi(first_multiple_input[2]);

        int result = closestNumber(a, b, x);

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
