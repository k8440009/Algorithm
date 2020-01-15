// 가르침
// https://www.acmicpc.net/problem/1062
/*
    시간복잡도
    O(2^21)
	1. a,c, n,t,i를 선택 가능 한가 체크
	2. 26가지중 K - 5개의 영어단어를 조합으로 구한다.
	5가지를 체크해 놓고, 체크가 안되있을 때 선택하면 5개의 단어를 선택한 채로 dfs를 돌릴 수 있다.

    비트마스크를 사용하여 2^21로 계산해도 될 듯
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 26;
int N, K, answer = 0;
bool selected[MAX];
vector<string> words;
void dfs(int curr, int cnt)
{
    if (cnt == K)
    {
        int result = N;
        for (string s : words)
        {
            for (char c : s)
            {
                if (!selected[c - 'a'])
                {
                    result -= 1; // 모르는 단어가 있는 경우 결과 값 감소
                    break;
                }
            }
        }
        answer = max(answer, result);
        return;
    }

    for (int i = curr; i < MAX; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;
            dfs(i + 1, cnt + 1);
            selected[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    // K가 5 보다 작으면 단어를 외울 수 없다.
    if (K < 5)
        answer = 0;
    // 모든 단어를 아는 경우
    else if (K == 26)
        answer = N;
    else
    {
        selected['a' - 'a'] = true;
        selected['c' - 'a'] = true;
        selected['i' - 'a'] = true;
        selected['n' - 'a'] = true;
        selected['t' - 'a'] = true;
        // a,c,i,n,t 개수만큼 감소
        K -= 5;
        words.resize(N);
        for (int i = 0; i < N; i++)
        {
            cin >> words[i];
            words[i] = words[i].substr(4, words[i].length());
        }
        dfs(0, 0);
    }
    cout << answer << '\n';
    return 0;
}
