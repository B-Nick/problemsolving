#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY steps as parameter.
 */

// !!!!! int -> long
long solve(std::vector<std::vector<int>> steps)
{
    enum {A = 0, B, COUNT};

    if (steps.empty() || steps.size() > 100)
    {
        throw std::invalid_argument("Invalid step count");
    }
    if (steps.at(0).at(A) < 1 || steps.at(0).at(A) > 1000000)
    {
        throw std::invalid_argument("Invalid a");
    }
    if (steps.at(0).at(B) < 1 || steps.at(0).at(B) > 1000000)
    {
        throw std::invalid_argument("Invalid b");
    }

    const int n {static_cast<int>(steps.size())};
    std::array<int, COUNT> intersect = {steps.at(0).at(A), steps.at(0).at(B)};
    for (int i = 1; i < n; ++i)
    {
        if (steps.at(i).size() != 2)
        {
            throw std::invalid_argument("Invalid step");
        }
        if (steps.at(i).at(A) < 1 || steps.at(i).at(A) > 1000000)
        {
            throw std::invalid_argument("Invalid a");
        }
        if (steps.at(i).at(B) < 1 || steps.at(i).at(B) > 1000000)
        {
            throw std::invalid_argument("Invalid b");
        }

        intersect[A] = std::min(intersect.at(A), steps.at(i).at(A));
        intersect[B] = std::min(intersect.at(B), steps.at(i).at(B));
    }
    return static_cast<long>(intersect.at(A)) * intersect.at(B);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> steps(n);

    for (int i = 0; i < n; i++) {
        steps[i].resize(2);

        string steps_row_temp_temp;
        getline(cin, steps_row_temp_temp);

        vector<string> steps_row_temp = split(rtrim(steps_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int steps_row_item = stoi(steps_row_temp[j]);

            steps[i][j] = steps_row_item;
        }
    }

    // !!!!! int -> long
    long result = solve(steps);

    std::cout << result << std::endl;

    fout << result << "\n";

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
