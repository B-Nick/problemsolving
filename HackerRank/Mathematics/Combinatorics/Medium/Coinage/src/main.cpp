#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY coins
 */

namespace
{
enum Denomination {A = 0, B, C, D, DENOMINATION_COUNT};
using Cache = std::unordered_map<int, int>;



Cache cache;


struct Frame final
{
    int n;
    int k;
    std::vector<int> coins = {0,0,0,0};
};

}

int getWays(const int n, const int k, const std::vector<int> &coins)
{
    static const std::array<int, DENOMINATION_COUNT> denominationMap {1, 2, 5, 10};

    if (!n)
    {
        return 1;                       // base case
    }
    if (n < 0 || k <= 0) return 0;      // base case

    const int key {n * 1000 + coins.at(k - 1) * 10 + k};



    if (!cache.count(key))
    {
        std::vector<int> newCoins(coins);
        const int dn {denominationMap.at(k - 1)};
        --newCoins[k - 1];
        const int dk = newCoins.at(k - 1) <= 0 ? 1 : 0;

        const int x = getWays(n - dn, k - dk, newCoins)
                      + getWays(n, k - 1, coins);

        cache[key] = x;
    }
    return cache.at(key);
}


int solve(int n, std::vector<int> coins)
{
    if (n < 1 || n > 1000)
    {
        throw std::invalid_argument("Invalid sum");
    }
    if (coins.size() != DENOMINATION_COUNT)
    {
        throw std::invalid_argument("Invalid denominations");
    }
    if (coins.at(A) < 1 || coins.at(A) > 10000)
    {
        throw std::invalid_argument("Invalid 1s count");
    }
    if (coins.at(B) < 1 || coins.at(B) > 1000)
    {
        throw std::invalid_argument("Invalid 2s count");
    }
    if (coins.at(C) < 1 || coins.at(C) > 1000)
    {
        throw std::invalid_argument("Invalid 5s count");
    }
    if (coins.at(D) < 1 || coins.at(D) > 1000)
    {
        throw std::invalid_argument("Invalid 10s count");
    }

    cache.clear();


    return getWays(n, static_cast<int>(coins.size()), coins);
}

/* Explicit stack
int solve(int n, std::vector<int> coins)
{
    if (n < 1 || n > 1000)
    {
        throw std::invalid_argument("Invalid sum");
    }
    if (coins.size() != DENOMINATION_COUNT)
    {
        throw std::invalid_argument("Invalid denominations");
    }
    if (coins.at(A) < 1 || coins.at(A) > 10000)
    {
        throw std::invalid_argument("Invalid ₹1s count");
    }
    if (coins.at(B) < 1 || coins.at(B) > 1000)
    {
        throw std::invalid_argument("Invalid ₹2s count");
    }
    if (coins.at(C) < 1 || coins.at(C) > 1000)
    {
        throw std::invalid_argument("Invalid ₹5s count");
    }
    if (coins.at(D) < 1 || coins.at(D) > 1000)
    {
        throw std::invalid_argument("Invalid ₹10s count");
    }

    static const std::array<int, DENOMINATION_COUNT> denominationMap {1, 2, 5, 10};

    std::stack<Frame> frameStack;
    frameStack.push({n, static_cast<int>(coins.size()), coins});
    int counter {0};
    while (!frameStack.empty())
    {
        const Frame frame {frameStack.top()};
        frameStack.pop();

        if (frame.k > 1)
        {
            frameStack.push({frame.n, frame.k - 1, frame.coins});
        }
        std::vector<int> newCoins(frame.coins);
        const int dn {denominationMap.at(frame.k - 1)};
        --newCoins[frame.k - 1];
        const int dk = newCoins.at(frame.k - 1) <= 0 ? 1 : 0;
        const int nn {frame.n - dn};
        const int nk {frame.k - dk};

        if (!nn)
        {
            ++counter;

        }
        else if (nn > 0 && nk > 0)
        {
            frameStack.push({nn, nk, newCoins});
        }
    }
    return counter;

}
*/


#define IN input

int main()
{
    ifstream input;
    input.open("../test3.txt");

    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(IN, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(IN, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string coins_temp_temp;
        getline(IN, coins_temp_temp);

        vector<string> coins_temp = split(rtrim(coins_temp_temp));

        vector<int> coins(4);

        for (int i = 0; i < 4; i++) {
            int coins_item = stoi(coins_temp[i]);

            coins[i] = coins_item;
        }

        int result = solve(n, coins);

        std::cout << result << std::endl;



        fout << result << "\n";
    }

    input.close();

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

/*
int getWays(const int n, const int k, const std::vector<int> &coins, Cache &cache)
{
    static const std::array<int, DENOMINATION_COUNT> denominationMap {1, 2, 5, 10};

    if (!n)
    {
        return 1;       // base case
    }
    if (n < 0 || k <= 0) return 0;    // base case

    const int key {n * 10000 + coins.at(k - 1) * 10 + k};

    if (!cache.count(n))
    {
        cache[n] = std::unordered_map<int, int>();
    }
    else if (cache.at(n).count(key))
    {
        return cache.at(n).at(key);
    }
    if (!cache.at(n).count(key))
    {
        std::vector<int> newCoins(coins);
        const int dn {denominationMap.at(k - 1)};
        --newCoins[k - 1];
        const int dk = newCoins.at(k - 1) <= 0 ? 1 : 0;

        const int x = getWays(n - dn, k - dk, newCoins, cache)
                                         + getWays(n, k - 1, coins, cache);

        cache[n][key] = x;
    }
    return cache.at(n).at(key);
}*/

/*namespace
{
enum Denomination {A = 0, B, C, D, DENOMINATION_COUNT};
using Cache = std::unordered_map<int, int>;

struct Frame final
{
    int n;
    int k;
    std::vector<int> coins = {0,0,0,0};
    bool m;
};

}

int getWays(const int n, const int k, const std::vector<int> &coins, Cache &cache)
{
    static const std::array<int, DENOMINATION_COUNT> denominationMap {1, 2, 5, 10};

    if (!n)
    {
        return 1;                       // base case
    }
    if (n < 0 || k <= 0) return 0;      // base case

    const int key {n * 10000 + coins.at(k - 1) * 10 + k};



    if (!cache.count(key))
    {
        std::vector<int> newCoins(coins);
        const int dn {denominationMap.at(k - 1)};
        --newCoins[k - 1];
        const int dk = newCoins.at(k - 1) <= 0 ? 1 : 0;

        const int x = getWays(n - dn, k - dk, newCoins, cache)
                                         + getWays(n, k - 1, coins, cache);

        cache[key] = x;
    }
    return cache.at(key);
}




int solve(int n, std::vector<int> coins)
{
    if (n < 1 || n > 1000)
    {
        throw std::invalid_argument("Invalid sum");
    }
    if (coins.size() != DENOMINATION_COUNT)
    {
        throw std::invalid_argument("Invalid denominations");
    }
    if (coins.at(A) < 1 || coins.at(A) > 10000)
    {
        throw std::invalid_argument("Invalid ₹1s count");
    }
    if (coins.at(B) < 1 || coins.at(B) > 1000)
    {
        throw std::invalid_argument("Invalid ₹2s count");
    }
    if (coins.at(C) < 1 || coins.at(C) > 1000)
    {
        throw std::invalid_argument("Invalid ₹5s count");
    }
    if (coins.at(D) < 1 || coins.at(D) > 1000)
    {
        throw std::invalid_argument("Invalid ₹10s count");
    }

    //Cache cache;

    //return getWays(n, static_cast<int>(coins.size()), coins, cache);

    static const std::array<int, DENOMINATION_COUNT> denominationMap {1, 2, 5, 10};

    Cache cache;

    std::stack<Frame> frameStack;
    frameStack.push({n, static_cast<int>(coins.size()), coins, true});
    int counter {0};
    while (!frameStack.empty())
    {
        const Frame frame {frameStack.top()};
        frameStack.pop();

        const int key {frame.n * 10000 + frame.coins.at(frame.k - 1) * 10 + frame.k};
        if (cache.count(key))
        {
            counter += cache.at(key);
            continue;
        }
        if (frame.k > 1)
        {
            frameStack.push({frame.n, frame.k - 1, frame.coins, false});
        }
        std::vector<int> newCoins(frame.coins);
        const int dn {denominationMap.at(frame.k - 1)};
        --newCoins[frame.k - 1];
        const int dk = newCoins.at(frame.k - 1) <= 0 ? 1 : 0;
        const int nn {frame.n - dn};
        const int nk {frame.k - dk};

        if (!nn)
        {
            ++counter;

        }
        else if (nn > 0 && nk > 0)
        {
            frameStack.push({nn, nk, newCoins, true});
        }

        if (!frame.m)
        {
            cache[key] = counter;
        }





}


return counter;

}*/
