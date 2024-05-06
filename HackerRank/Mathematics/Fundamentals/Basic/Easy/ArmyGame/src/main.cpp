#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gameWithCells' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

// n is column (or row) count
// 1 or 2 rows (or columns) => ((1 + n) / 2) * 1 packages
// 3 or 4 rows (or columns) => ((1 + n) / 2) * 2 packages
// 5 or 6 rows (or columns) => ((1 + n) / 2) * 3 packages
// ...
// m rows (or columns) => ((n + 1) / 2) * ((m + 1) / 2)
// Integer division

int gameWithCells(int n, int m)
{
    if (n < 0 || n > 1000) throw std::invalid_argument("Invalid n");
    if (m < 0 || m > 1000) throw std::invalid_argument("Invalid m");

    return ((n + 1) >> 1) * ((m + 1) >> 1);

    // return ((n + 1) / 2) * ((m + 1) / 2);   // parentheses matter (integer division!)

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    /*string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int result = gameWithCells(n, m);

    fout << result << "\n";*/

    int n = 134;
    int m = 4;

    int result = gameWithCells(n, m);

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
