// 대표값 2
// https://www.acmicpc.net/problem/2587
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sum = 0;
    vector<int> nums(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    sort(nums.begin(), nums.end());
    cout << sum / 5 << '\n';
    cout << nums[2] << '\n';

    return 0;
}