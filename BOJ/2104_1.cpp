// 부분배열 고르기
// https://www.acmicpc.net/problem/2104
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<long long> nums;

long long divideAndConquer(int left, int right);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    cout << divideAndConquer(0, N - 1);
    return 0;
}

long long divideAndConquer(int left, int right)
{
    // 기저 사례
    if (left == right)
        return nums[left] * nums[left];
    int mid = (left + right) / 2;
    long long result = max(divideAndConquer(left, mid), divideAndConquer(mid + 1, right)); // 부분 배열 중 최대를 찾는다.
    int low = mid, high = mid + 1;
    long long sum = nums[low] + nums[high];
    long long minValue = min(nums[low], nums[high]);
    result = max(result, sum * minValue);

    while (left < low || high < right)
    {
        if (high < right && (low == left || nums[low - 1] < nums[high + 1]))
        {
            high += 1;
            sum += nums[high];
            minValue = min(minValue, nums[high]);
        }
        else
        {
            low -= 1;
            sum += nums[low];
            minValue = min(minValue, nums[low]);
        }

        result = max(result, sum * minValue);
    }

    return result;
}