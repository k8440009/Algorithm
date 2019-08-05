// 로또
// https://www.acmicpc.net/problem/6603
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        // 입력
        // 집합의 크기, 집합
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<bool> lotte(n, false);
        for (int i = 0; i < n - 6; i++)
            lotte.push_back(true);
        for (int i = 0; i < 6; i++)
            lotte.push_back(false);

        // 내림차순으로 되어 있으면 생략 가능
        // sort(lotte.begin(), lotte.end());

        vector<vector<int>> answer;
        do
        {
            vector<int> current;
            for (int i = 0; i < n; i++)
            {
                if (lotte[i])
                    current.push_back(a[i]);
            }
            answer.push_back(current);
        } while (next_permutation(lotte.begin(), lotte.end()));
        sort(answer.begin(), answer.end());

        for (auto v : answer)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}