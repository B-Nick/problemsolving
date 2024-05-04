#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    if (n < 1 || n > 10000) throw std::invalid_argument("Invalid array length");
    if (k < 1 || k > n) throw std::invalid_argument("Invalid subarray length");

    std::deque<int> maxIndexWindowDeque;    // index of max is on the front
        // indexes of potentially maxes within current
        // window are on the back
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < 1 || arr[i] > 10000) throw std::invalid_argument("Invalid value");

        while (!maxIndexWindowDeque.empty() && arr[i] > arr[maxIndexWindowDeque.back()])
        {
            maxIndexWindowDeque.pop_back();
        }
        maxIndexWindowDeque.push_back(i);
        // indexes <= i - k are out of window now
        while (!maxIndexWindowDeque.empty() && maxIndexWindowDeque.front() <= i - k)
        {
            maxIndexWindowDeque.pop_front();
        }
        if (i >= k - 1)
        {
            std::cout << arr[maxIndexWindowDeque.front()] << " ";
        }
    }
    std::cout << std::endl;
}

int main(){

    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
