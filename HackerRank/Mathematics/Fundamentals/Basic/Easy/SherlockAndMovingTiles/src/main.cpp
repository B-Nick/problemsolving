#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'movingTiles' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER s1
 *  3. INTEGER s2
 *  4. INTEGER_ARRAY queries
 */

std::vector<double> movingTiles(int l, int s1, int s2, std::vector<long> queries)
{
    if (l < 1 || l > 1000000000) throw std::invalid_argument("Invalid side length");
    if (s1 < 1 || s1 > 1000000000) throw std::invalid_argument("Invalid speed of the first square");
    if (s2 < 1 || s2 > 1000000000) throw std::invalid_argument("Invalid speed of the second square");
    if (queries.empty()|| queries.size() > 100000)
    {
        throw std::invalid_argument("Invalid query count");
    }
    if (s1 == s2) throw std::invalid_argument("Speeds cannot be the same");

    const int q = queries.size();
    const long square = static_cast<long>(l) * l;
    std::vector<double> result(q);
    const double sqrt2 = std::sqrt(2);

    for (int i = 0; i < q; ++i)
    {
        const long currQuery = queries.at(i);
        if (currQuery < 1 || currQuery > square) throw std::invalid_argument("Invalid query");

        result[i] = sqrt2 * (l - std::sqrt(static_cast<double>(currQuery))) / std::abs(s1 - s2);
    }
    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    /*string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int l = stoi(first_multiple_input[0]);

    int s1 = stoi(first_multiple_input[1]);

    int s2 = stoi(first_multiple_input[2]);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<long> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }*/



    int l = 1000000;
    int s1 = 1000004;
    int s2 = 1000003;
    std::vector<long> queries = {258385599125,
                                248989464296,
                                115376367013,
                                539529357307};

    std::vector<double> result = movingTiles(l, s1, s2, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << std::fixed << std::setprecision(7) << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    for (size_t i = 0; i < result.size(); i++) {
        std::cout << std::fixed << std::setprecision(7) <<  result[i];

        if (i != result.size() - 1) {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;

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

