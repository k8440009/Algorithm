// 숫자 카드 2
// https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10000000 + 1;
int N, M;
vector<int> Plus(MAX);
vector<int> Minus(MAX);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a >= 0)
            Plus[a]++;
        else
            Minus[abs(a)]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        if (a >= 0)
            cout << Plus[a] << ' ';
        else
            cout << Minus[abs(a)] << ' ';
    }
}