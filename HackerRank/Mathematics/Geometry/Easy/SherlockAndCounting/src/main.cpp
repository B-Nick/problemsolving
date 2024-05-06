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
 *  2. INTEGER k
 */

int solve(int n, int k)
{
    assert(n >= 1 && k <= 1000000000);

    // -i * i + n * i - n * k <= 0 square inequation
    // i * i - n * i + n * k >= 0 , i < n
    // D = n * n - 4 * n * k
    // i = (n +- sqrt(D)) / 2, D >= 0

    const long d = static_cast<long>(n) * n - 4 * static_cast<long>(n) * k;

    if (d > 0)  // 2 roots
    {
        const double sqrtD {std::sqrt(static_cast<double>(d))};
        const int il {static_cast<int>(std::floor((n - sqrtD) / 2.0))};
        const int ir {static_cast<int>(std::ceil((n + sqrtD) / 2.0))};
        // i > 0 && i < n
        return il + n - ir;
    }
    // single root or no roots, i > 0 && i < n && i is integer
    return n - 1;
}

//#define IN std::cin
#define IN infile

//#define OUT std::cout
#define OUT outfile

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    ifstream infile;
    infile.open("../test0.txt");

    ofstream outfile;
    outfile.open("../test0-r.txt");

    string q_temp;
    getline(IN, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    //std::cout << q << std::endl;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(IN, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        int result = solve(n, k);

        OUT << result << std::endl;

        fout << result << "\n";
    }

    fout.close();

    infile.close();
    outfile.close();

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
