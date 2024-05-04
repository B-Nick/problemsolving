#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#include <numeric>

// Write your Student class here

class Student final
{
public:
    void input()
    {
        static const int N = 5;
        for (int i = 0; i < N; ++i)
        {
            int currentScore;
            std::cin >> currentScore;
            if (!std::cin) throw std::logic_error("Score read error");
            if (currentScore < 0 || currentScore > 50) throw std::logic_error("Invalid score");
            scores.push_back(currentScore);
        }
    }
    int calculateTotalScore() const
    {
        return std::accumulate(scores.cbegin(), scores.cend(), 0);
    }

private:
    std::vector<int> scores;
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
