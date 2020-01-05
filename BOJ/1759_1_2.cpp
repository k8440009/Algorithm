// 암호 만들기
// https://www.acmicpc.net/problem/1759
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int L, C;
vector<char> alpha;
vector<string> answer;
bool check(string str)
{
    int mo = 0, ja = 0;
    for (char now : str)
    {
        if (now == 'a' || now == 'e' || now == 'i' || now == 'o' || now == 'u')
            mo++;
        else
            ja++;
    }
    // 모음 최소 1개, 자음 최소 2개
    if (mo >= 1 && ja >= 2)
        return true;
    return false;
}
void dfs(int pos, string str)
{
    // 기저 1: string 완성
    if (str.size() == L)
    {
        // 모음과 자음 갯수 체크
        if (check(str))
            answer.push_back(str);
        return;
    }
    // pos를 넘어가는 경우
    if (pos == C)
        return;

    char now = alpha[pos];
    dfs(pos + 1, str + now);
    dfs(pos + 1, str);
}
void init()
{
    cin >> L >> C;
    alpha.resize(C);
    for (int i = 0; i < C; i++)
        cin >> alpha[i];
    sort(alpha.begin(), alpha.end());
    /*
    vector<char>::iterator iter;
    for (iter = alpha.begin(); iter != alpha.end(); iter++)
        cout << *iter << ' ';
    cout << '\n';
    */
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    dfs(0, ""); // pos, string
    vector<string>::iterator iter;
    for (iter = answer.begin(); iter != answer.end(); iter++)
        cout << *iter << '\n';
    return 0;
}

/*
    백트래킹을 적용하기 위해서는 완전 탐색을 먼저 구현하고, 그 다음 백트래킹을 진행한다.
    완전 탐색이 되지 않는데 백트래킹을 진행하면 알고리즘 그자체가 틀린것이다.
    사실, 이번 문제는 완전 탐색에 가깝다.
*/