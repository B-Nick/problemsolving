#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int digitSum(int n)
{
    int result {0};
    while (n)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main()
{
    std::string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    if (n < 1 || n > 100000)
    {
        std::cerr << "Invalid n" << std::endl;
    }
    if (n < 10)
    {
        std::cout << n << std::endl;
        return 0;
    }

    int curr = 1;
    int currSum = 1;
    const int sqrtN = std::sqrt(n);

    auto checkAndSet = [&curr, &currSum](int divisor)
    {
        const int dSum = digitSum(divisor);
        if (dSum > currSum)
        {
            curr = divisor;
            currSum = dSum;
        }
        else if (dSum == currSum &&
                 divisor < curr)
        {
            curr = divisor;
        }
    };

    for (int d = 1; d <= sqrtN; ++d)
    {
        if (!(n % d))
        {
            checkAndSet(d);
            checkAndSet(n / d);
        }
    }
    std::cout << curr << std::endl;
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
