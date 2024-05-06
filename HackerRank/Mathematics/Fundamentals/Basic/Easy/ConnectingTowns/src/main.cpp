#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'connectingTowns' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY routes
 */

int connectingTowns(int n, std::vector<int> routes)
{
    static const int MOD = 1234567;

    if (n <= 2 || n > 100) throw std::invalid_argument("Invalid town count");
    if (routes.size() < n - 1) throw std::invalid_argument("Invalid town count");

    const int m = n - 1;

    int currCount = 1;
    for (int i = 0; i < m; ++i)
    {
        if (routes.at(i) < 1 && routes.at(i) > 1000) throw std::invalid_argument("Invalid route count");

        currCount = (currCount * routes.at(i)) % MOD;
    }
    return currCount;
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

        string routes_temp_temp;
        getline(cin, routes_temp_temp);

        vector<string> routes_temp = split(rtrim(routes_temp_temp));

        vector<int> routes(n - 1);

        for (int i = 0; i < n - 1; i++) {
            int routes_item = stoi(routes_temp[i]);

            routes[i] = routes_item;
        }

        int result = connectingTowns(n, routes);

        fout << result << "\n";
    }*/

    int n = 4;
    vector<int> routes = {3, 4 ,5};


    int result = connectingTowns(n, routes);

    std::cout << result << std::endl;

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
