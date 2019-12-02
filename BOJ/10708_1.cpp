// 크리스마스 파티
// https://www.acmicpc.net/problem/10708
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> friends, target;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    friends.resize(N + 1), target.resize(M);

    for (int i = 0; i < M; i++)
        cin >> target[i];

    // 경기
    for (int i = 0; i < M; i++)
    {
        int cnt = 0;
        // 친구
        for (int j = 1; j <= N; j++)
        {
            int check;
            cin >> check;
            if (target[i] == check)
                friends[j] += 1;
            else
                cnt++;
        }

        friends[target[i]] += cnt;
    }

    for (int i = 1; i <= N; i++)
        cout << friends[i] << '\n';

    return 0;
}