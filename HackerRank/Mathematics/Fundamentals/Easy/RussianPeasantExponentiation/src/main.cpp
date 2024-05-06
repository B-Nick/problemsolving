#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 *  3. LONG_INTEGER k
 *  4. INTEGER m
 */



std::vector<int> solve(int a, int b, long k, int m)
{
    if (k < 0l || k > 1000000000000000000l)
    {
        throw std::invalid_argument("Invalid exponent");
    }
    if (m < 2 || m > 1000000000)
    {
        throw std::invalid_argument("Invalid modulo");
    }
    if (a < 0 || a > m || b < 0 || b > m)
    {
        throw std::invalid_argument("Invalid number");
    }

    long long c {1ll};
    long long  d {0ll};
    // e + i * f
    long long  e {a};
    long long  f {b};
    while (k > 0l)
    {
        if (k & 1l)
        {
            const long long pc {c};
            c = (m + (c * e) % m - (d * f) % m) % m;
            d = ((d * e) % m + (pc * f) % m) % m;
        }
        // (e + i * f) ^ 2 = e^2 -f^2 + i * 2 * e * f
        const long long x = (e * e) % m;
        const long long y = (f * f) % m;
        const long long pe {e};
        e = (m + x - y) % m;
        f = (pe * f * 2) % m;
        //f = (f << 1) % m;
        k >>= 1l;
    }
    return {static_cast<int>(c), static_cast<int>(d)};
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int a = stoi(first_multiple_input[0]);

        int b = stoi(first_multiple_input[1]);

        long k = stol(first_multiple_input[2]);

        int m = stoi(first_multiple_input[3]);

        std::vector<int> result = solve(a, b, k, m);

        for (std::size_t i = 0; i < result.size(); i++) {
            std::cout << result[i];

            if (i != result.size() - 1) {
                std::cout << " ";
            }
        }

        std::cout << std::endl;

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

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
