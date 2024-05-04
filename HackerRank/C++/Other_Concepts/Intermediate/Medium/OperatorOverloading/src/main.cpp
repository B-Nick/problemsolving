#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define a data()

class Matrix final
{
public:
    Matrix operator+ (const Matrix &_other) const
    {
        Matrix result;

        if (m_data.size() != _other.m_data.size())
        {
            throw std::invalid_argument("Incompatible matrices");
        }
        const int n = m_data.size();

        for (int i = 0; i < n; ++i)
        {
            result.m_data.push_back(std::vector<int>());
            if (m_data.at(i).size() != _other.m_data.at(i).size())
            {
                throw std::invalid_argument("Incompatible matrices");
            }
            const int m = m_data.at(i).size();
            for (int j = 0; j < m; ++j)
            {
                result.m_data.at(i).push_back(m_data.at(i).at(j) + _other.m_data.at(i).at(j));
            }
        }
        return result;
    }

    std::vector<std::vector<int>> &data() {return m_data;};

private:
    std::vector<std::vector<int>> m_data;

};



int main () {
    int cases,k;
    cin >> cases;
    for(k=0;k<cases;k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n,m,i,j;
        cin >> n >> m;
        for(i=0;i<n;i++) {
            vector<int> b;
            int num;
            for(j=0;j<m;j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for(i=0;i<n;i++) {
            vector<int> b;
            int num;
            for(j=0;j<m;j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x+y;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
