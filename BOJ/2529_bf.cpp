// 부등호
// https://www.acmicpc.net/problem/2529
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &perm, vector<char> &ch)
{
    for (int i = 0; i < ch.size(); i++)
    {
        if (ch[i] == '<' && perm[i] > perm[i + 1])
            return false;
        if (ch[i] == '>' && perm[i] < perm[i + 1])
            return false;
    }
    return true;
}
int main()
{
    int N;
    cin >> N;
    vector<char> ch(N);
    vector<int> big(N + 1);
    vector<int> small(N + 1);

    for (int i = 0; i < N; i++)
        cin >> ch[i];

    for (int i = 0; i <= N; i++)
    {
        big[i] = 9 - i;
        small[i] = i;
    }

    do
    {
        if (check(big, ch))
            break;

    } while (prev_permutation(big.begin(), big.end()));

    for (int i = 0; i <= N; i++)
        cout << big[i];
    cout << '\n';

    do
    {
        if (check(small, ch))
            break;

    } while (next_permutation(small.begin(), small.end()));

    for (int i = 0; i <= N; i++)
        cout << small[i];

    return 0;
}