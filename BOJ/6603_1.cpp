// 로또
// https://www.acmicpc.net/problem/6603
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 50;
int N;
vector<int> number;
bool selected[MAX];
void dfs(int index, int cnt)
{
    if (cnt == 6)
    {
        for (int i = 0; i < N; i++)
        {
            if (selected[i])
                cout << number[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = index; i < N; i++)
    {
        selected[i] = true;
        dfs(i + 1, cnt + 1);
        selected[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        fill_n(selected, MAX, 0);
        number.resize(N);
        for (int i = 0; i < N; i++)
            cin >> number[i];

        dfs(0, 0);
        cout << '\n';

        number.clear();
    }
}
