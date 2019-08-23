// 부등호
// https://www.acmicpc.net/problem/2529
#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX = 10;

vector<string> answer;
vector<char> c;
bool visited[MAX];
bool check(char x, char y, char op)
{
    if (op == '<')
    {
        if (x > y)
            return false;
    }
    if (op == '>')
    {
        if (x < y)
            return false;
    }
    return true;
}
void dfs(int index, string num)
{
    // 기저 사례
    if (index == n + 1)
    {
        answer.push_back(num);
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (visited[i])
            continue;
        // index가 0 일때는 pass
        // 이전값과, 현재 값, 부등호를 함께 비교 후 체크
        if (index == 0 || check(num[index - 1], i + '0', c[index - 1]))
        {
            visited[i] = true;
            dfs(index + 1, num + to_string(i));
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    c.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    // 백트래킹으로 시간을 줄임
    dfs(0, "");
    //auto p = minmax_element(answer.begin(), answer.end());
    pair<vector<string>::iterator, vector<string>::iterator> p = minmax_element(answer.begin(), answer.end());
    cout << *p.second << '\n';
    cout << *p.first << '\n';
    return 0;
}