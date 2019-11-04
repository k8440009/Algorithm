// 농구 경기
// https://www.acmicpc.net/problem/1159
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
int name[27];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        name[str[0] - 'a']++;
    }

    vector<char> answer;
    for (int i = 0; i < 27; i++)
    {
        if (name[i] > 4)
            answer.push_back(i + 'a');
    }

    if (answer.size() == 0)
        cout << "PREDAJA" << '\n';
    else
    {
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i];
    }
    return 0;
}