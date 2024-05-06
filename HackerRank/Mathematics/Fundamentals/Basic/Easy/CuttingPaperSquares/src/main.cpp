#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

// f(1, m) = m - 1   o oo ooo
// f(2, m) = 2 * f(1, m) + 1  o oo ooo
//                            o oo ooo
// f(3, m) = 3 * (1, m) + 2
// ...

// f(n, m) = n * f(1, m) + n - 1 = n * (m - 1) + n - 1 = n * m - 1

long solve(int n, int m)
{
    if (n < 1 || n > 1000000000) throw std::invalid_argument("Invalid n");
    if (m < 1 || m > 1000000000) throw std::invalid_argument("Invalid m");

    return static_cast<long>(n) * m - 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    /*string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    long result = solve(n, m);

    fout << result << "\n";*/

    int n = 3;

    int m = 1;

    long result = solve(n, m);

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
