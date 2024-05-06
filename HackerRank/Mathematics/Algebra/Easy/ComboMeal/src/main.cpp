#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'profit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER b
 *  2. INTEGER s
 *  3. INTEGER c
 */

int profit(int b, int s, int c)
{
    if (c < 3 || c > 2000)
    {
        throw std::invalid_argument("Invalid combo price");
    }
    if (b < 2 || b >= c)
    {
        throw std::invalid_argument("Invalid burger price");
    }
    if (s < 2 || s >= c)
    {
        throw std::invalid_argument("Invalid soda price");
    }
    if (b + s < c)
    {
        throw std::invalid_argument("Invalid prices combination");
    }

    // x0 is the making cost of x, where x: b, s, c
    // b0 + p = b, s0 + p = s, c0 + p = c, c0 = b0 + s0 (system 4 eq, 4 vars)
    // => b0 = b - p, s0 = s - p, b0 + s0 + p = c
    // => p = b + s - c

    return b + s - c;
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

        int b = stoi(first_multiple_input[0]);

        int s = stoi(first_multiple_input[1]);

        int c = stoi(first_multiple_input[2]);

        int result = profit(b, s, c);

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
