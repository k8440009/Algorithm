// 숫자 카드
// https://www.acmicpc.net/problem/10815
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000000 + 1;
int N, M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        bool flag = false;
        int start = 0, end = N - 1;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (a[mid] == num)
            {
                flag = true;
                break;
            }
            else if (a[mid] < num)
                start = mid + 1;
            else
                end = mid - 1;
        }

        if (flag)
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
}
/*
    참고
    https://jaimemin.tistory.com/991
*/