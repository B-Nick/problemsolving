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
 *  1. INTEGER a
 *  2. INTEGER b
 *  3. INTEGER n
 */

namespace
{
const int MOD {1000000007};
}   // namespace

std::vector<std::vector<int>> squareMatrixMultiplication(const std::vector<std::vector<int>> &lhs,
                                                            const std::vector<std::vector<int>> &rhs)
{
    assert(lhs.size() == rhs.size());

    const int size {static_cast<int>(lhs.size())};
    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            for (int k = 0; k < size; ++k)
            {
                const long mul {(static_cast<long>(lhs.at(i).at(k)) * rhs.at(k).at(j)) % MOD};
                result[i][j] = static_cast<int>((result.at(i).at(j) + mul) % MOD);
            }
        }
    }
    return result;
}

std::vector<std::vector<int>> squareMatrixPower(const std::vector<std::vector<int>> &m, const int p)
{
    const int size {static_cast<int>(m.size())};
    static const std::vector<std::vector<int>> identityMatrix = {{1, 0}, {0, 1}};

    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));

    if (p == 0) return identityMatrix;
    std::vector<std::vector<int>> mp(squareMatrixPower(m, p >> 1));
    if (p & 1)
    {
        return squareMatrixMultiplication(squareMatrixMultiplication(mp, mp), m);
    }
    return squareMatrixMultiplication(mp, mp);
}

int solve(int a, int b, int n)
{
    static const std::vector<std::vector<int>> matrixFibonacci = {{1, 1}, {1, 0}};

    if (a < 1 || b < 1 || n < 1 ||
        a > 1000000000 || b > 1000000000 || n > 1000000000)
    {
        throw std::invalid_argument("Invalid input data");
    }

    const std::vector<std::vector<int>> matrixFibonacciN {squareMatrixPower(matrixFibonacci, n - 1)};
    return (static_cast<long>(matrixFibonacciN.at(0).at(0)) * b +
            static_cast<long>(matrixFibonacciN.at(0).at(1)) * a) % MOD;
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

        int n = stoi(first_multiple_input[2]);

        int result = solve(a, b, n);

        std::cout << result << std::endl;

        fout << result << "\n";
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
