#define io(arr) std::cin >> arr

#define foreach(arr, j) for (std::size_t j = 0; (j) < arr.size(); ++j)

#define INF 1000000000

#define FUNCTION(functionName, cmp) void (functionName)(int &m, const int e) { if (e cmp m) m = e; }

#define toStr(x) #x

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result =) <<' '<< ans;
    return 0;
}
