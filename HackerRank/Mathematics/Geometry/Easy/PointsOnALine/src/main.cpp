#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);



int main()
{
    static const std::string YES {"YES"};
    static const std::string NO {"NO"};

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (n < 2 || n > 10)
    {
        std::cerr << "Invalid point count" << std::endl;
    }

    int prevX {-1000}, prevY {-1000};
    int mode {0};   // 0 - init, 1 - vert, 2 - hor
    for (int n_itr = 0; n_itr < n; n_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);

        if (x < -10 || x > 10 || y < -10 || y > 10)
        {
            std::cerr << "Invalid point" << std::endl;
        }

        if (prevX < -10 || prevY < -10)
        {
            assert(!mode);

            prevX = x;
            prevY = y;
        }
        else
        {
            if (!std::abs(prevX - x) && (!mode || mode == 1))
            {
                mode = 1;
                continue;
            }
            else if (!std::abs(prevY - y) && (!mode || mode == 2))
            {
                mode = 2;
                continue;
            }
            std::cout << NO << std::endl;
            return 0;
        }
    }

    std::cout << YES << std::endl;
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
