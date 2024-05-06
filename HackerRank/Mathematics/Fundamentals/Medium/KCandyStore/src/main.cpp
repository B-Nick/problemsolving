#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

// C(n, k) = n! / k! / (n - k)!
// C(n - 1, k - 1) = (n - 1)! / (k - 1)! / (n - 1 - k + 1)! = k*(n - 1)! / (k*(k - 1)!) / (n - k)! = k*(n - 1)! / k! / (n - k)!
// C(n - 1, k) = (n - 1)! / k! / (n - 1 - k)! = (n - k)*(n - 1)! / k! / ((n - k)*(n - k - 1)!) = (n - k)*(n - 1)! / k! / (n - k)!
// => C(n - 1, k - 1) + C(n, k - 1) = (k*(n - 1)! + (n - k)*(n - 1)!) / k! / (n - k)! = (n - k + k)*(n - 1)! / k! / (n - k)! =
// = n*(n - 1)! / k! / (n - k)! = n! / k! / (n - k)! = C(n, k) (*)
// C(n, 0) = n! / 0! / n! = 1 (**), C(n, n) = n! / n! / 0! = 1 (***); (*), (**), (***) - Pascal's Triangle recurrent rules
int binomialCoeff(int n, int k)
{
    static const long MOD = 1000000000l; // ? From nCr Table

    static std::vector<std::vector<int>> binomialCoeffs = {{1}, {1, 1}};

    int nc = binomialCoeffs.size() - 1;


    if (nc < n)
    {
        while (nc++ < n)
        {
            binomialCoeffs.push_back({1});
            for (int i = 1; i < nc; ++i)
            {
                binomialCoeffs[nc].push_back((static_cast<long>(binomialCoeffs.at(nc - 1).at(i - 1))
                                              + binomialCoeffs.at(nc - 1).at(i)) % MOD);
            }
            binomialCoeffs[nc].push_back(1);
        }
    }

    assert(n <= nc);

    return binomialCoeffs.at(n).at(k);
}


int solve(int n, int k)
{
    if (n < 1 || n >= 1000)
    {
        throw std::invalid_argument("Invalid candy count");
    }
    if (k < 1 || k >= 1000)
    {
        throw std::invalid_argument("Invalid bought candy count");
    }

     // Number of combinations with repetitions: CR(n, k) = C(n + k - 1, k)
    return binomialCoeff(n + k - 1, k);
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

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        int result = solve(n, k);

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


//binomialCoeffs.push_back({1});
/*const int kc = binomialCoeffs.at(nc).size() - 1;
    if (kc < k)
    {
        if (kc == -1) binomialCoeffs[nc].push_back(1);
        const int m = k == nc ? k - 1 : k;
        for (int j = kc + 1; j <= m; ++j)
        {
            binomialCoeffs[nc].push_back((static_cast<long>(binomialCoeffs.at(nc - 1).at(j - 1))
                                          + binomialCoeffs.at(nc - 1).at(j)) % MOD);
        }
        if (k == nc) binomialCoeffs[nc].push_back(1);
    }*/

//assert(static_cast<unsigned>(k) <= binomialCoeffs.at(n).size() - 1);
