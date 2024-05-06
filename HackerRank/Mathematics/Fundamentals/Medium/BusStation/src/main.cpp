#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

// brute-force checking
bool checkSize(const int possibleSize, const std::vector<int> &a)
{
    const int n {static_cast<int>(a.size())};
    for (int i = 0; i < n; )
    {
        int j {i};
        int sum {0};
        while (sum < possibleSize && j < n)
        {
            sum += a.at(j++);
        }
        if (sum > possibleSize ||
            (sum < possibleSize && j > n))
        {
            return false;
        }
        i = j;
    }
    return true;
}


std::vector<int> solve(std::vector<int> a)
{
    if (a.empty() || a.size() > 100000)
    {
        throw std::invalid_argument("Invalid groups count");
    }

    int sum {0};    // max capacity
    int minCap {std::numeric_limits<int>::min()};  // min capacity
    for (const int &e : a)
    {
        if (e < 1 || e > 10000)
        {
            throw std::invalid_argument("Invalid group");
        }
        sum += e;
        if (e > minCap) minCap = e;
    }

    const int sqrtMaxCap {static_cast<int>(std::sqrt(sum))};
    std::vector<int> possibleSizes;
    // find all divisors of max possible bus size (sum)
    // such that divisor >= min possible bus size
    // only check range [1..sqrt(sum)]
    // as each divisor has a conjugated one (e.g. 6 and 2 for 12)
    for (int i = 1; i <= sqrtMaxCap; ++i)
    {
        if (!(sum % i))
        {
            if (i >= minCap)
            {
                possibleSizes.push_back(i);
            }
            const int conjugatedI {sum / i};
            if (conjugatedI >= minCap && conjugatedI != i)
            {
                possibleSizes.push_back(conjugatedI);
            }
        }
    }
    std::sort(possibleSizes.begin(), possibleSizes.end());

    // we need to take into account the order of groups
    // by beans of checking each divisor found;
    const int m {static_cast<int>(possibleSizes.size())};
    for (int j = 0; j < m - 1; ++j)
    {
        if (!checkSize(possibleSizes.at(j), a))
        {
            possibleSizes[j] = -1;
        }
    }
    std::vector<int> result;
    for (const int p : possibleSizes)
    {
        if (p > 0) result.push_back(p);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    std::vector<int> result = solve(a);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    for (std::size_t i = 0; i < result.size(); i++) {
        std::cout << result[i];

        if (i != result.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    fout << "\n";

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
