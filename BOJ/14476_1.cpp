// 최대공약수 하나 빼기
// https://www.acmicpc.net/problem/14476
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> nums, leftGcd, rightGcd;
int gcd(int a, int b)
{

    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return abs(a);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    nums.resize(N), leftGcd.resize(N), rightGcd.resize(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    leftGcd[0] = nums[0];
    for (int i = 1; i < N; i++)
        leftGcd[i] = gcd(leftGcd[i - 1], nums[i]);
    rightGcd[N - 1] = nums[N - 1];
    for (int i = N - 2; i >= 0; i--)
        rightGcd[i] = gcd(rightGcd[i + 1], nums[i]);

    int answerGcd = 0, location = 0;
    if (nums[0] < rightGcd[1] || gcd(nums[0], rightGcd[1]) != rightGcd[1])
    {
        answerGcd = rightGcd[1];
    }
    // 하나하나 뺴면서 계싼
    for (int i = 1; i < N; i++)
    {

        if (i == N - 1)
        {
            if (nums[i] % leftGcd[i] != 0)
            {
                if (answerGcd < leftGcd[i])
                {
                    answerGcd = leftGcd[i];
                    location = i;
                }
            }
        }
        else
        {

            int merge = gcd(leftGcd[i - 1], rightGcd[i + 1]);
            if (nums[i] % merge != 0)
            {
                if (answerGcd < merge)
                {
                    answerGcd = merge;
                    location = i;
                }
            }
        }
    }

    if (answerGcd == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << answerGcd << ' ' << nums[location] << '\n';
    }
    return 0;
}

/*
    참고
    https://hororolol.tistory.com/83
*/