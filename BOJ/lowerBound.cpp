// upperBound
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr;
    arr.push_back(1); // 0
    arr.push_back(2); // 1
    arr.push_back(4); // 2
    arr.push_back(5); // 3
    arr.push_back(6); // 4
    arr.push_back(6); // 5
    arr.push_back(7); // 6
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(9);

    int num = lower_bound(arr.begin(), arr.end(), 6) - arr.begin();
    cout << num << ' ' << arr[num];
}