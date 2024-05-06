#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isFibo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

std::string isFibo(long n)
{
    static const std::string YES("IsFibo");
    static const std::string NO("IsNotFibo");

    if (n < 0 || n > 10000000000l)
    {
        throw std::invalid_argument("Invalid n");
    }

    static std::vector<long> sequence = {0, 1, 1};

    int currIdx = sequence.size() - 1;
    long currNumber = sequence.at(currIdx);
    if (n >= currNumber)
    {
        while (currNumber < n)
        {
            ++currIdx;
            currNumber = sequence.at(currIdx - 1) + sequence.at(currIdx - 2);
            sequence.push_back(currNumber);
        }
        return currNumber == n ? YES : NO;
    }
    const bool found = std::binary_search(sequence.cbegin(), sequence.cend(), n);
    return found ? YES : NO;
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

        long n = stol(ltrim(rtrim(n_temp)));

        std::string result = isFibo(n);

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
