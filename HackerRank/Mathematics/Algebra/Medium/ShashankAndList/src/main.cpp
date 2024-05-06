#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

namespace
{
static int MOD {1000000007};
}

int modPow2(long p)
{
    long result {1l};
    long b {2l};
    while (p)
    {
        if (p & 1) result = (result * b) % MOD;
        b = (b * b) % MOD;
        p >>= 1;
    }
    return static_cast<int>(result);
}

// Complete the solve function below.
// {a0, a1, ..., an} => S = 2^a0 + 2^a1 + ... + 2^an + 2^(a1 + a2) + ... + 2^(a[n-1] + an) + 2^(a1 + a2 + a3) + ... + 2^(a[n - 2] + a[n - 1] + an) + ... +
// + 2^(a1 + a2 + ... + an) = 2^a0 + 2^a1 + ... + 2^an + 2^a1 * 2^a2 + ... + 2^a1 * 2^a2 * ... * 2^an
// 2^a0 = x0, 2^a1 = x1, ..., 2^an = xn => S = x0 + x1 + ... + xn + x0 * x1 + ... + x[n - 1]*xn + ... + x1 * x2 * ... * xn = (x0 + 1) * (x1 + 1) * ... * (xn + 1) - 1
// Example n = 2:
// S2 = x0 + x1 + x2 + x0 * x1 + x0 * x2 + x1 * x2 + x0 * x1 * x2  = (x0 + 1) * (x1 + 1) * (x2 + 1) - 1
// => S = (2^a0 + 1) * (2^a1 + 1) * ... * (2^an + 1) - 1
int solve(std::vector<long> a)
{
    assert(!a.empty() && a.size() <= 100000);

    long s {1l};
    for (const long e : a)
    {
        assert(e >= 0l && e <= 10000000000l);

        s = (s * (modPow2(e) + 1) % MOD) % MOD;
    }
    s = (s - 1 + MOD) % MOD;

    return static_cast<int>(s);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<long> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        long a_item = stol(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    int result = solve(a);

    fout << result << "\n";

    std::cout << result << std::endl;


    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
