// 단어 수학
// https://www.acmicpc.net/problem/1339
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
	1. string에 포함된 단어 갯수를 체크
	2. 큰 숫자부터 m개를 뽑는다.
	3. 영어와 숫자를 매칭한 후 string값을 계산한다.

    속도가 아슬아슬 하니 논리 추가 필요
*/
int N;
int alpha[27];
vector<char> letter;
vector<string> words;
vector<int> number;
int calculate()
{
    int sum = 0, m = letter.size();
    for (int i = 0; i < m; i++)
        alpha[letter[i] - 'A'] = number[i];
    for (string s : words)
    {
        int now = 0;
        for (char c : s)
        {
            now = now * 10 + alpha[c - 'A'];
        }
        sum += now;
    }
    return sum;
}
void solve()
{
    int answer = 0;
    // 순열을 사용하여 알파벳에 숫자를 매칭
    do
    {
        int total = 0;
        total = calculate();
        answer = max(answer, total);
    } while (next_permutation(number.begin(), number.end()));
    cout << answer << '\n';
}
void init()
{
    cin >> N;
    words.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
        for (char c : words[i])
            letter.push_back(c); // 단어 갯수 체크
    }
    // 정렬 이후 중복 제거 => 사용하는 단어를 뽑을 수 있다.
    sort(letter.begin(), letter.end());
    letter.erase(unique(letter.begin(), letter.end()), letter.end());
    // 단어의 수 만큼 숫자를 뽑는다.
    int m = letter.size();
    for (int i = 9; i > 9 - m; i--)
        number.push_back(i);
    sort(number.begin(), number.end());
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    solve();
    return 0;
}
