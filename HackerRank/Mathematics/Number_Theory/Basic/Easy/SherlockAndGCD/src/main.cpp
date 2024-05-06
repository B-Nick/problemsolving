#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int getGCD(const int a, const int b)
{
    int x = std::max(a, b);
    int y = std::min(a, b);

    while (x %= y)
    {
        std::swap(x, y);
    }
    return y;
}

std::string solve(std::vector<int> a)
{
    static const std::string YES {"YES"};
    static const std::string NO {"NO"};

    if (a.empty() || a.size() > 100)
    {
        throw std::invalid_argument("Invalid array size");
    }

    if (std::find(a.cbegin(), a.cend(), 1) != a.cend())
    {
        return YES;
    }

    const int m {static_cast<int>(a.size())};
    int currentCumulativeGCD {a.at(0)};
    std::set<int> unique;
    for (int i = 1; i < m; ++i)
    {
        if (!unique.count(a.at(i)))
        {
            unique.insert(a.at(i));
            currentCumulativeGCD = getGCD(currentCumulativeGCD, a.at(i));
            if (currentCumulativeGCD == 1)
            {
                return YES;
            }
        }
    }
    return NO;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a_count_temp;
        getline(cin, a_count_temp);

        int a_count = stoi(ltrim(rtrim(a_count_temp)));

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(a_count);

        for (int i = 0; i < a_count; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        std::string result = solve(a);

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
