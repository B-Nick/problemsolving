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
 *  2. INTEGER m
 */

int factorialMod(int n, const int mod)
{
    int res = 1;
    while (n-- > 0)
    {
        res = (static_cast<long>(res) * (n + 1)) % mod;
    }
    return res;
}

// n * (n - 1) * (n - 2) * ... * k;
// if k == 1 => full factorial mod
int partialFactorialMod(int n, int k, const int mod)
{
    if (k > n + 1) throw std::invalid_argument("Invalid partialFactorialMod arguments");

    int res = 1;
    while (n >= k)
    {
        res = (static_cast<long>(res) * n--) % mod;
    }
    return res;
}

int extendedEuclidianAlgorithm(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1 {}, y1 {};
    int gcd = extendedEuclidianAlgorithm(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int solve(int n, int m)
{
    static const long MOD = 1000000007;  // prime!

    if (n < 1 || n > 1000) throw std::invalid_argument("Invalid 0's count");
    if (m < 1 || m > 1000) throw std::invalid_argument("Invalid 1's count");

    // C(m - 1, n + m - 1) = C(k, n + k) = C(k, t) = t! / k! / (t - k)! = t * (t - 1) * (t - 2) * ... * (t - k + 1) / k!
    // C(k, t) % MOD = (t * (t - 1) * (t - 2) * ... * (t - k + 1) * (1 /k!)) % MOD = ((t * (t - 1) * (t - 2) * ... * (t - k + 1)) % MOD * (1 /(t - k)!) % MOD) % MOD =
    // = (...((t % MOD * (t - 1) % MOD) % MOD * (t - 2) % MOD) % MOD * ...(... * (t - k + 1) % MOD) % ... % MOD) % MOD * inv(k) % MOD
    // inv(x) : (x * inv(x)) % MOD = 1 or (x * inv(x) - 1) = p * MOD (p is int, x * inv(x) has remainder 1 when divided by m, or x * inv(x) - 1 is divisible by m)
    // gcd(a, MOD) = 1 <=> a * x - 1 = y * MOD => x = inv(a) (% MOD)
    const int k = m - 1;
    const int t = n + k;
    const int maxD = std::max(k, n);    // n == t - k, C(k, t) = t ! / k! / (t - k)! = t ! / k! / (n + k - k)! = t! / k! / n!
    const int minD = std::min(k, n);    // t - k == n
    const int tFactPMod = partialFactorialMod(t, maxD + 1, MOD);
    const int divFactMod = partialFactorialMod(minD, 1, MOD);   // Full factorial
    int x {}, y {};
    extendedEuclidianAlgorithm(divFactMod, MOD, x, y); // x is inv(kFactMod) (% MOD)
    int invDivFactMod = (x  % MOD + MOD) % MOD;
    return (static_cast<long>(tFactPMod) * invDivFactMod) % MOD;
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

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = solve(n, m);

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
