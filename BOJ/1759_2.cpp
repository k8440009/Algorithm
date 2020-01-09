// 암호 만들기
// https://www.acmicpc.net/problem/1759
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int L, C;
vector<char> words;
vector<string> answer;
bool check(string str)
{
    int mo = 0, ja = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            mo++;
        else
            ja++;
    }
    if (mo >= 1 && ja >= 2)
        return true;
    return false;
}
void dfs(int current, string str)
{
    // 기저
    if (str.size() == L)
    {
        if (check(str))
            answer.push_back(str);
        return;
    }
    if (current == C)
    {
        return;
    }
    dfs(current + 1, str + words[current]);
    dfs(current + 1, str);
}
void init()
{
    cin >> L >> C;
    words.resize(C);
    for (int i = 0; i < C; i++)
        cin >> words[i];
    sort(words.begin(), words.end());
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    dfs(0, "");
    vector<string>::iterator iter;
    for (iter = answer.begin(); iter != answer.end(); iter++)
        cout << *iter << '\n';
    return 0;
}