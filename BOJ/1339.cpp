// 단어 수학
// https://www.acmicpc.net/problem/1339
#include <bits/stdc++.h>
using namespace std;
char alpha[256];
int calculate(vector<string> &str, vector<char> &letter, vector<int> &a)
{
    // 단어와, 숫자의 위치를 매칭
    int m = letter.size();
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        alpha[letter[i]] = a[i];
    }
    // string에서 숫자를 계산
    for (string s : str)
    {
        int now = 0;
        for (char c : s)
        {
            now = now * 10 + alpha[c];
        }
        sum += now;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<string> str(n);
    vector<char> letter;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        str[i] = temp;
        for (char c : temp)
            letter.push_back(c);
    }

    sort(letter.begin(), letter.end());
    letter.erase(unique(letter.begin(), letter.end()), letter.end());

    int m = letter.size();
    for (int i = 9; i > 9 - m; i--)
        a.push_back(i);
    sort(a.begin(), a.end());
    int answer = 0;
    do
    {
        int total = 0;
        // 계산
        // string 배열, 단어 갯수, 단어 선택 위치
        total = calculate(str, letter, a);
        answer = max(answer, total);
    } while (next_permutation(a.begin(), a.end()));
    cout << answer << '\n';
    return 0;
}