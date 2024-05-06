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
 *  1. INTEGER x1
 *  2. INTEGER y1
 *  3. INTEGER x2
 *  4. INTEGER y2
 */

#define LIM 1000000000

int gcd(int a, int b)
{
    assert(a >= b);

    if (a == b || !b) return a;
    return gcd(b, a % b);
}

int solve(int x1, int y1, int x2, int y2)
{
    if (x1 < -LIM || x1 > LIM) throw std::invalid_argument("Invalid x1");
    if (x2 < -LIM || x2 > LIM) throw std::invalid_argument("Invalid x2");
    if (y1 < -LIM || y1 > LIM) throw std::invalid_argument("Invalid y1");
    if (y2 < -LIM || y2 > LIM) throw std::invalid_argument("Invalid y2");

    const int dx = std::abs(x2 - x1);
    const int dy = std::abs(y2 - y1);

    if (!dy) return dx - 1;
    if (!dx) return dy - 1;

    if (!(dy % dx)) return dx - 1;


    if (!(dx % dy))
    {
        const int kinv = std::abs(dx / dy);

        assert(!(std::abs(x2 - x1) % kinv));

        return std::abs(x2 - x1) / kinv - 1;
    }

    int a;
    int b;
    if (dx >= dy) {a = dx; b = dy;}
    else {a = dy; b = dx;}

    const int sgcd = gcd(a, b);
    const int p = dy / sgcd;
    const int q = dx / sgcd;

    // k = dy / dx = p / q
    // b = r / q
    const long r = static_cast<long>(q) * y1 - static_cast<long>(p) * x1;

    // y = (p*x + r) / q

    const int x3 = x1 + q;
    const long nom = static_cast<long>(p) * x3 + r;
    if (nom % q) return 0;
    return std::abs(x2 - x1) / q - 1;
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

        int x1 = stoi(first_multiple_input[0]);

        int y1 = stoi(first_multiple_input[1]);

        int x2 = stoi(first_multiple_input[2]);

        int y2 = stoi(first_multiple_input[3]);

        int result = solve(x1, y1, x2, y2);

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
