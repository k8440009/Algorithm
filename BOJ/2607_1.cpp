// 비슷한 단어
// https://www.acmicpc.net/problem/2607
#include <iostream>
#include <string>
using namespace std;
int N;
int alpha1[26], alpha2[26];
void init()
{
    string str;
    cin >> N >> str;
    for (int i = 0; i < str.size(); i++)
        alpha1[str[i] - 'A']++;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int answer = 0;

    for (int i = 0; i < N - 1; i++)
    {
        string str;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
            alpha2[str[i] - 'A']++;

        int flag = true;
        int cnt1 = 0, cnt2 = 0;
        // 비교
        for (int i = 0; i < 26; i++)
        {
            // 다를 때
            if (alpha1[i] != alpha2[i])
            {
                if (alpha1[i] > alpha2[i])
                    cnt1 += (alpha1[i] - alpha2[i]);
                else
                    cnt2 += (alpha2[i] - alpha1[i]);
            }
            // 두개 갯수가 1보다 큰 경우
            if (cnt1 > 1 || cnt2 > 1)
                break;
            if (i == 25)
                answer++;
        }

        fill_n(alpha2, 26, 0);
    }
    cout << answer;
    return 0;
}