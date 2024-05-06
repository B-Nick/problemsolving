#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a DOUBLE.
 * The function accepts 2D_INTEGER_ARRAY coordinates as parameter.
 */

double solve(std::vector<std::vector<int>> coordinates)
{
    enum Coord {X = 0, Y = 1};
    static const int M {1000000000};

    if (coordinates.size() < 2 || coordinates.size() > 1000000)
    {
        throw std::invalid_argument("Invalid dot count");
    }
    int minX {std::numeric_limits<int>::max()};
    int maxX {std::numeric_limits<int>::min()};
    int minY {minX};
    int maxY {maxX};

    for (const std::vector<int> &dot : coordinates)
    {
        if (dot.size() != 2)
        {
            throw std::invalid_argument("Invalid dot");
        }
        const int x {dot.at(Coord::X)};
        const int y {dot.at(Coord::Y)};
        if ((x && y) || x < -M || x > M || y < -M || y > M)
        {
            throw std::invalid_argument("Invalid coordinates");
        }

        if (!y)
        {
            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
        }
        else
        {
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }
    }
    double maxDist {static_cast<double>(maxX) - minX};
    double testDist {static_cast<double>(maxY) - minY};
    if (testDist > maxDist) maxDist = testDist;
    const int maxAbsX {std::max(std::abs(maxX), std::abs(minX))};
    const int maxAbsY {std::max(std::abs(maxY), std::abs(minY))};
    testDist = std::sqrt(static_cast<long>(maxAbsX) * maxAbsX +
                         static_cast<long>(maxAbsY) * maxAbsY);
    if (testDist > maxDist) maxDist = testDist;
    return maxDist;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> coordinates(n);

    for (int i = 0; i < n; i++) {
        coordinates[i].resize(2);

        string coordinates_row_temp_temp;
        getline(cin, coordinates_row_temp_temp);

        vector<string> coordinates_row_temp = split(rtrim(coordinates_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int coordinates_row_item = stoi(coordinates_row_temp[j]);

            coordinates[i][j] = coordinates_row_item;
        }
    }

    double result = solve(coordinates);

    fout << std::fixed << std::setprecision(6) << result << "\n";

    std::cout << std::fixed << std::setprecision(6) << result << std::endl;

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
