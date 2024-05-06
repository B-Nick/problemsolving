#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'primeCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */


std::vector<long> calculatePrefixProducts(const std::vector<int> &v)
{
    std::vector<long> result(v.size());
    result[0] = v.at(0);
    for (std::vector<int>::size_type i = 1; i < v.size(); ++i)
    {
        result[i] = result.at(i - 1) * v.at(i);
    }
    return result;
}

int primeCount(long n)
{
    static const long Max = 1000000000000000000l;
    // pre-computed primes 2 * 3 * 5 * ... * 47 ~ 6e17 (max possible)
    static const std::vector<int> primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
    };

    // {2, 6, 30, 210, ... }
    static const std::vector<long> rangeBounds(calculatePrefixProducts(primes));

    if (n < 1 || n > Max) throw std::invalid_argument("Invalid n");

    if (n == 1) return 0l;

    return std::distance(rangeBounds.cbegin(),
                         std::upper_bound(rangeBounds.cbegin(), rangeBounds.cend(), n));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    /*string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        int result = primeCount(n);

        fout << result << "\n";
    }*/

    long n = 1000l;

    int result = primeCount(n);

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
