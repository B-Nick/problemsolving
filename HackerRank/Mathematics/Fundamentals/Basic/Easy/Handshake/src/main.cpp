#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'handshake' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

// Solution in closed form
// C(2, n) - binomial coefficient (number of ways to choose an (unordered)
// subset of 2 elements from a fixed set of n elements)
// C(2, n) = n! / (k! * (n - k)!) =
// = n * (n - 1) * (n - 2) * ... * 1 / (2! * (n - 2) * ... * 1) =
// = n * (n - 1) / 2
int handshake(int n)
{
    if (n < 1 || n > 1000000) throw std::invalid_argument("Invalid attendees");

    return (n * (n - 1)) / 2; // may not fit in int?
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

        int result = handshake(n);

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
