// 시험 감독 - 2회 시간: 20분
// https://www.acmicpc.net/problem/13458
#include <iostream>
#include <vector>
using namespace std;

int N, B, C;
vector <int> A;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    A.resize(N);
    long long cnt = 0;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    cin >> B >> C;
    for(int i = 0; i < N; i++)
    {
        int total = A[i] - B;
        cnt += 1;
        if (total <= 0)
            continue;
        else if(total % C == 0)
            cnt += (total / C);
        else
        {
            cnt += (total / C);
            cnt += 1;
        }   
    }
    cout << cnt << '\n';
}