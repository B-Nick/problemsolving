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
 *  1. INTEGER d
 *  2. INTEGER k
 */

std::string solve(int d, int k)
{
    static const std::string PSB {"possible"};
    static const std::string IMPSB {"impossible"};

    assert(d >= 1 && d <= 2000000000);
    assert(k >= 0 && k <= 2000000000);

    int pointCount {0};
    const int r {static_cast<int>(std::sqrt(d))};
    for (int x = 1; x <= r; ++x)
    {
        const int x2 {x * x};
        const int y {static_cast<int>(std::sqrt(d - x2))};
        if (x2 + y * y == d) ++pointCount;
    }
    return k >= pointCount << 2 ? PSB : IMPSB;
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

        int d = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        string result = solve(d, k);

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
