#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


// 0 1 2 3 4 5 6 7 8 9 -> 9 0 8 1 7 2 6 3 5 4
// if k < n / 2 => i = k / 2 + 1
// if k >= n => i = 2 * (n - 1) - 2 * k = 2 * (n - 1 - k)
int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));
    if (t < 1 || t > 50)
    {
        std::cerr << "Invalid test cases number";
        return -1;
    }

    while (t--)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        if (n < 1 || n > 100000)
        {
            std::cerr << "Invalid n";
            return -2;
        }
        if (k < 0 || k >= n)
        {
            std::cerr << "Invalid k";
            return -3;
        }

        const int half = n >> 1;
        if (k < half)
        {
            std::cout << (k << 1) + 1 << std::endl;
        }
        else
        {
            std::cout << ((n - 1 - k) << 1) << std::endl;
        }
    }


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
