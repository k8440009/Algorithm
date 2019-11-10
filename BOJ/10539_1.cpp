// 수빈이와 수열
// https://www.acmicpc.net/problem/10539
#include <iostream>
using namespace std;
const int MAX = 100;
int N;
int A[MAX], B[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> B[i];

    A[0] = B[0];

    int total = A[0];
    int cnt = 1;
    for (int i = 1; i < N; i++)
    {
        cnt++;
        A[i] = B[i] * cnt - total;
        total += A[i];
    }

    for (int i = 0; i < N; i++)
        cout << A[i] << ' ';
}