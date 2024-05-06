#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER n as parameter.
 */


std::vector<int> solve(int n)
{
    static const int MOD {1000000000};
    static std::vector<std::vector<int>> c = {{1}, {1, 1}};

    if (n < 1 || n >= 1000)
    {
        throw std::invalid_argument("Invalid n");
    }

    std::vector<int> result;
    const int m {static_cast<int>(c.size())};
    if (n < m)
    {
        return c.at(n);
    }
    for (int i = m; i <= n; ++i)
    {
        c.push_back(std::vector<int>(i + 1));
        c[i][0] = c[i][i] = 1;
        const int hi {(i >> 1) + 1};
        int k = 1;
        for (; k < hi; ++k)
        {
            c[i][k] = (c[i - 1][k] + c[i - 1][k - 1]) % MOD;
        }
        for (; k < i; ++k)
        {
            c[i][k] = c[i][i - k];
        }
    }
    return c[n];
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

        int n = stoi(ltrim(rtrim(n_temp)));

        std::vector<int> result = solve(n);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        for (std::size_t i = 0; i < result.size(); i++) {
            std::cout << result[i];

            if (i != result.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;

        fout << "\n";
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
