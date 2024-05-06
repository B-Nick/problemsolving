#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'divisors' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int divisors(int n)
{
    if (n < 1 || n > 1000000000) throw std::invalid_argument("Invalid number");

    if (n & 1) return 0;

    // prime factorization
    std::map<int, int> factorDegrees;
    factorDegrees.insert({2, 0});
    while (n > 1 && !(n & 1))
    {
        ++factorDegrees[2];
        n >>= 1;
    }

    int sqrtN = std::sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2)
    {
        const int n0 = n;
        while (!(n % i))
        {
            if (!factorDegrees.count(i))
            {
                factorDegrees.insert({i, 0});
            }
            ++factorDegrees[i];
            n = n / i;
        }
        if (n0 != n) sqrtN = std::sqrt(n);

    }
    if (n > 2)
    {
        if (!factorDegrees.count(n))
        {
            factorDegrees.insert({n, 0});
        }
        ++factorDegrees[n];
    }

    int totalDivisorCount = 1;
    int oddfDivisorCount = 1;
    for (const auto &fd : factorDegrees)
    {
        totalDivisorCount *= fd.second + 1;
        if (fd.first != 2)
        {
            oddfDivisorCount *= fd.second + 1;
        }

        //std::cout << fd.first << " " << fd.second << " ";

    }
    //const int res = (totalDivisorCount * factorDegrees.at(2)) / (factorDegrees.at(2) + 1);

    const int res = totalDivisorCount - oddfDivisorCount;

    //std::cout << std::endl;
    //std::cout << totalDivisorCount << std::endl;

    return res;

    // Brute force
    /*const int half = n >> 1;
    int counter {0};
    for (int d = 2; d <= half; d+=2)
    {
        if (!(n % d)) ++counter;
    }
    return counter + 1;*/

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

        int result = divisors(n);

        fout << result << "\n";
    }*/

    int n = 32;

    int result = divisors(n);

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
