#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

#define BIN_CEILING 65536

typedef unsigned long long ull;


ull getKth90Number(unsigned k)
{
    static ull cache[BIN_CEILING] = {0};
    if (cache[k] > 0) return cache[k];

    ull result = 0ull;
    ull currBit = 1ull;
    ull currDec = 1ull;
    while (k >= currBit)
    {
        if (k & currBit)
        {
            const ull term = currDec * 9ull;
            result += term;
        }
        currBit <<= 1;
        currDec *= 10ull;
    }
    cache[k] = result;
    return result;
}


std::string solve(const int n)
{
    if (n < 1 || n > 500) throw std::invalid_argument("Invalid number");

    for (unsigned i = 1; i < BIN_CEILING; ++i)
    {
        const ull nn = getKth90Number(i);
        const unsigned un = static_cast<unsigned>(n);

        //std::cout << nn << std::endl;

        if (nn >= un && !(nn % un)) return std::to_string(nn);
    }
    return "Not found";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    /*string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = solve(n);

        fout << result << "\n";
    }*/


    //for (int i = 1; i <= 500; ++i)
    //{
        int i = 90;
        std::string result = solve(i);
        std::cout << result << std::endl;
    //}



    // fout << result << "\n";


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
