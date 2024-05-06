#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY dates as parameter.
 */

int convert2Dec(int x, const int fromBase)
{
    int result {0};
    int currBaseOrd {1};
    while (x)
    {
        const int currDigit {x % 10};
        if (currDigit >= fromBase)
        {
            throw std::logic_error("base");
        }
        result += currBaseOrd * (x % 10);
        x /= 10;
        currBaseOrd *= fromBase;
    }
    return result;
}

// FIXED
long solve(std::vector<std::vector<int>> dates)
{
    enum Date {Month = 0, Day = 1};
    static const int MAX {37}; // 31(12) == 37(10) is max number

    if (dates.empty() || dates.size() > 100000)
    {
        throw std::invalid_argument("Invalid date");
    }

    long matchCount[MAX] = {0};
    for (const std::vector<int> &currDate : dates)
    {
        if (currDate.size() != 2)
        {
            throw std::invalid_argument("Invalid date");
        }
        if (currDate.at(Month) < 1 || currDate.at(Month) > 12)
        {
            throw std::invalid_argument("Invalid month");
        }
        if (currDate.at(Day) < 1 || currDate.at(Day) > 31)
        {
            throw std::invalid_argument("Invalid day");
        }
        // Unary base is invalid.
        if (currDate.at(Month) == 1) continue;
        int dec {-1};
        if (currDate.at(Month) == 10)
        {
            dec = currDate.at(Day);
        }
        else
        {
            try
            {
                dec = convert2Dec(currDate.at(Day), currDate.at(Month));
            }
            catch (const std::logic_error &e)
            {
                if (std::string(e.what()) == "base") continue;
                throw;
            }
        }

        assert(dec > 0);

        ++matchCount[dec - 1];
    }

    long result {0l};
    for (int i = 0; i < MAX; ++i)
    {
        result += (matchCount[i] - 1) * matchCount[i] >> 1; // C(matchCount[i], 2)
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> dates(n);

    for (int i = 0; i < n; i++) {
        dates[i].resize(2);

        string dates_row_temp_temp;
        getline(cin, dates_row_temp_temp);

        vector<string> dates_row_temp = split(rtrim(dates_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int dates_row_item = stoi(dates_row_temp[j]);

            dates[i][j] = dates_row_item;
        }
    }

    long result = solve(dates);

    fout << result << "\n";

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
