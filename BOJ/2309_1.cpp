// 일곱 난쟁이
// https://www.acmicpc.net/problem/2309
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dwaf(9);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> dwaf[i];
        total += dwaf[i];
    }

    sort(dwaf.begin(), dwaf.end());

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            int now = total - dwaf[i] - dwaf[j];
            if (now == 100)
            {
                for (int k = 0; k < 9; k++)
                    if (k != i && k != j)
                        cout << dwaf[k] << '\n';
                return 0;
            }
        }
    }
}