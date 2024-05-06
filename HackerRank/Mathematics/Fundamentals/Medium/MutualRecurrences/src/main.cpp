#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 *  3. INTEGER c
 *  4. INTEGER d
 *  5. INTEGER e
 *  6. INTEGER f
 *  7. INTEGER g
 *  8. INTEGER h
 *  9. LONG_INTEGER n
 */

namespace
{
const int MOD {1000000000};
}   // namespace

std::vector<std::vector<int>> matrixMultiplication(const std::vector<std::vector<int>> &lhs,
                                                   const std::vector<std::vector<int>> &rhs)
{
    assert(lhs.size() == rhs.size());

    const int rowCount {static_cast<int>(lhs.size())};
    const int colCount {static_cast<int>(rhs.at(0).size())};
    std::vector<std::vector<int>> result(rowCount, std::vector<int>(colCount, 0));

    for (int i = 0; i < rowCount; ++i)
    {
        for (int j = 0; j < colCount; ++j)
        {
            for (int k = 0; k < rowCount; ++k)
            {
                const long mul {(static_cast<long>(lhs.at(i).at(k)) * rhs.at(k).at(j)) % MOD};
                result[i][j] = static_cast<int>((result.at(i).at(j) + mul) % MOD);
            }
        }
    }
    return result;
}

std::vector<std::vector<int>> buildIdentityMatrix(const int n)
{
    assert(n < 100);

    std::vector<std::vector<int>> identityMatrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        identityMatrix[i][i] = 1;
    }
    return identityMatrix;
}

/*std::vector<std::vector<int>> squareMatrixPower(const std::vector<std::vector<int>> &m, const int p)
{
    const int size {static_cast<int>(m.size())};
    static const std::vector<std::vector<int>> identityMatrix{buildIdentityMatrix(size)};

    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));
    if (p == 0) return identityMatrix;
    std::vector<std::vector<int>> mp(squareMatrixPower(m, p >> 1));
    if (p & 1)
    {
        return matrixMultiplication(matrixMultiplication(mp, mp), m);
    }
    return matrixMultiplication(mp, mp);
}*/

std::vector<std::vector<int>> squareMatrixPower(std::vector<std::vector<int>> m, long p)
{
    const int size {static_cast<int>(m.size())};
    static const std::vector<std::vector<int>> identityMatrix{buildIdentityMatrix(size)};

    std::vector<std::vector<int>> result(identityMatrix);
    while (p > 0l)
    {
        if (p & 1l)
        {
            result = matrixMultiplication(result, m);
        }
        m = matrixMultiplication(m, m);
        p >>= 1l;
    }
    return result;
}

std::vector<std::vector<int>> buildTransitionMatrix(const int a, const int b,
                                                    const int c, const int d,
                                                    const int e, const int f,
                                                    const int g, const int h,
                                                    const int coeffsMax)
{
    const int n {coeffsMax * 2 + 4};
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    ++matrix[0][0 - 1 + a]; // x[i - a] // a is 1-based, matrix is 0-based
    ++matrix[0][coeffsMax]; // i * d^i
    ++matrix[0][coeffsMax + 2 - 1 + b]; // y[i - b]
    ++matrix[0][coeffsMax + 2 - 1 + c]; // y[i - c]
    matrix[coeffsMax][coeffsMax] = d;
    matrix[coeffsMax][coeffsMax + 1] = d;
    matrix[coeffsMax + 1][coeffsMax + 1] = d;
    for (int i = 0; i < coeffsMax - 1; ++i)
    {
        ++matrix[i + 1][i];
    }

    const int termIdx {(coeffsMax << 1) + 2};
    ++matrix[coeffsMax + 2][coeffsMax + 2 - 1 + e]; // y[i - e]
    ++matrix[coeffsMax + 2][termIdx];   // i * h^i
    ++matrix[coeffsMax + 2][f - 1]; // x[f - e]
    ++matrix[coeffsMax + 2][g - 1]; // x[g - e]
    matrix[termIdx][termIdx] = h;
    matrix[termIdx][termIdx + 1] = h;
    matrix[termIdx + 1][termIdx + 1] = h;
    for (int i = coeffsMax + 2; i < termIdx - 1; ++i)
    {
        ++matrix[i + 1][i];
    }

    /*for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << matrix.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }*/

    return matrix;
}

std::vector<std::vector<int>> buildInitState(const int coeffsMax)
{
    const int n {coeffsMax * 2 + 4};
    std::vector<std::vector<int>> vec(n, std::vector<int>(1, 1));    // column vector
    vec[coeffsMax][0] = 0;
    vec[(coeffsMax << 1) + 2][0] = 0;

/*    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 1; ++j)
        {
            std::cout << vec.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }*/

    return vec;
}

std::vector<int> solve(int a, int b, int c, int d, int e, int f, int g, int h, long n)
{
    static const int coeffsMin {1};
    static const int coeffsMax {10 - 1};


    if (n < 1l || n > 1000000000000000000l)
    {
        throw std::invalid_argument("Invalid index");
    }
    if (a < coeffsMin || a > coeffsMax || b < coeffsMin || b > coeffsMax || c < coeffsMin || c > coeffsMax ||
        d < coeffsMin || d > coeffsMax || e < coeffsMin || e > coeffsMax || f < coeffsMin || f > coeffsMax ||
        g < coeffsMin || g > coeffsMax || h < coeffsMin || h > coeffsMax)
    {
        throw std::invalid_argument("Invalid parameter");
    }

    const std::vector<std::vector<int>> trMatrix {buildTransitionMatrix(a, b, c, d,
                                                                        e, f, g, h, coeffsMax)};
    const std::vector<std::vector<int>> trMatrixN {squareMatrixPower(trMatrix, n + 1)};
    const std::vector<std::vector<int>> initStateVector {buildInitState(coeffsMax)};

    const std::vector<std::vector<int>> resCol{matrixMultiplication(trMatrixN, initStateVector)};
    std::vector<int> result;
    result.push_back(resCol.at(0).at(0));
    result.push_back(resCol.at(coeffsMax + 2).at(0));

    return result;
}

#define IN std::cin // fileIn

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    ifstream fileIn;
    fileIn.open("../test0.txt", std::ios::in);

    string t_temp;
    getline(IN, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(IN, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int a = stoi(first_multiple_input[0]);

        int b = stoi(first_multiple_input[1]);

        int c = stoi(first_multiple_input[2]);

        int d = stoi(first_multiple_input[3]);

        int e = stoi(first_multiple_input[4]);

        int f = stoi(first_multiple_input[5]);

        int g = stoi(first_multiple_input[6]);

        int h = stoi(first_multiple_input[7]);

        long n = stol(first_multiple_input[8]);

        std::vector<int> result = solve(a, b, c, d, e, f, g, h, n);

        for (std::size_t i = 0; i < result.size(); i++) {
            std::cout << result[i];

            if (i != result.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fileIn.close();

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
