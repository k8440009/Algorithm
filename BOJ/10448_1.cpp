// 유레카 이론
// https://www.acmicpc.net/problem/10448
#include <iostream>
#include <vector>
using namespace std;
vector<int> table;
int N;
bool ureka(int total)
{
    for (int i = 0; i < table.size(); i++)
        for (int j = 0; j < table.size(); j++)
            for (int k = 0; k < table.size(); k++)
                if (table[i] + table[j] + table[k] == total)
                    return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 입력
    int tc;
    cin >> tc;
    // 삼각수 미리 계산
    int n = 1;
    while ((n) * (n + 1) / 2 < 1000)
    {
        table.push_back((n) * (n + 1) / 2);
        n++;
    }
    // 테스트
    for (int ts = 1; ts <= tc; ts++)
    {
        cin >> N;
        cout << ureka(N) << '\n';
    }
    return 0;
}