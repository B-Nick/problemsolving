#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY points as parameter.
 */

std::string solve(std::vector<std::vector<int>> points)
{
    static const std::string YES {"YES"};
    static const std::string NO {"NO"};

    enum Coord {X = 0, Y, Z, N};

    assert(points.size() == 4);

    const int n {static_cast<int>(points.size())};
    std::vector<std::vector<int>> vectors(3);
    for (int i = 1; i < n; ++i)
    {
        const auto p = points.at(i);

        assert(p.size() == N);

        for (int j = 0; j < N; ++j)
        {
            assert(p.at(j) >= -1000 && p.at(j) <= 1000);

            vectors[i - 1].push_back(p.at(j) - points.at(0).at(j));
        }
    }
    const auto mixedProduct = vectors.at(0).at(0) * (vectors.at(1).at(1) * vectors.at(2).at(2) -
                                                     vectors.at(2).at(1) * vectors.at(1).at(2)) -
                              vectors.at(0).at(1) * (vectors.at(1).at(0) * vectors.at(2).at(2) -
                                                     vectors.at(2).at(0) * vectors.at(1).at(2)) +
                              vectors.at(0).at(2) * (vectors.at(1).at(0) * vectors.at(2).at(1) -
                                                     vectors.at(2).at(0) * vectors.at(1).at(1));
    return mixedProduct ? NO : YES;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {

        vector<vector<int>> points(4);

        for (int i = 0; i < 4; i++) {
            points[i].resize(3);

            string points_row_temp_temp;
            getline(cin, points_row_temp_temp);

            vector<string> points_row_temp = split(rtrim(points_row_temp_temp));

            for (int j = 0; j < 3; j++) {
                int points_row_item = stoi(points_row_temp[j]);

                points[i][j] = points_row_item;
            }
        }

        std::string result = solve(points);

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
