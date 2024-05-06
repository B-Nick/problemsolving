#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY operations
 */

long solve(int n, vector<vector<int>> operations)
{
    static const int LEFT = 0;
    static const int RIGHT = 1;
    static const int ADD = 2;

    if (n < 3 || n > 10000000) throw std::invalid_argument("Invalid jar count");
    if (operations.empty() || operations.size() > 100000)
    {
        throw std::invalid_argument("Invalid operation count");
    }

    std::map<int, long> jarsBounded; // ordered by a
    for (const auto &currOperation : operations)
    {
        if (currOperation.empty() || currOperation.size() < ADD + 1)
        {
            throw std::invalid_argument("Invalid operation");
        }
        const int a = currOperation.at(LEFT);
        const int b = currOperation.at(RIGHT);
        const int k = currOperation.at(ADD);

        if (a < 1 || b > n || b < a || k < 0 || k > 1000000)
        {
            throw std::invalid_argument("Invalid operation");
        }

        if (jarsBounded.find(a) == jarsBounded.end())
        {
            jarsBounded.insert({a, 0l});
        }
        if (jarsBounded.find(b + 1) == jarsBounded.end())
        {
            jarsBounded.insert({b + 1, 0l});
        }
        jarsBounded[a] += k;
        jarsBounded[b + 1] -= k;
    }
    long sum {0};
    int prevJarIdx = 0;
    long currIntervalJar = 0;
    for (const auto &jarBounded : jarsBounded)
    {
        const int deltaIdx = jarBounded.first - prevJarIdx - 1;
        prevJarIdx = jarBounded.first;
        sum += currIntervalJar * deltaIdx;
        currIntervalJar += jarBounded.second;
        sum += currIntervalJar;
    }
    std::cout << sum << std::endl;

    return sum / n;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> operations(m);

    for (int i = 0; i < m; i++) {
        operations[i].resize(3);

        string operations_row_temp_temp;
        getline(cin, operations_row_temp_temp);

        vector<string> operations_row_temp = split(rtrim(operations_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int operations_row_item = stoi(operations_row_temp[j]);

            operations[i][j] = operations_row_item;
        }
    }

    long result = solve(n, operations);

    fout << result << "\n";

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
