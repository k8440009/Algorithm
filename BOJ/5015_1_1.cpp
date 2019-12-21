// ls (O(N^3))
// https://www.acmicpc.net/problem/5015
#include <iostream>
#include <string>
using namespace std;
const int MAX = 100 + 1;
// -1은 아직 답이 계산되지 않았음을 의미
// 1은 해당 입력들이 서로 대응됨을 의미
// 0은 해당 입력들이 서로 대응되지 않음을 의미
int cache[MAX][MAX];
int N;
string S, W; // 패턴, 문자열
// 와일드카드 패턴 W[w//]가 문자열 S[s..]에 대응 되는지 여부 반환
bool matchMemoized(int w, int s)
{
    // 메모이제이션
    int &ret = cache[w][s];
    if (ret != -1)
        return ret;
    // W[w]와 S[s]를 맞춰나간다.
    while (s < S.size() && w < W.size() && W[w] == S[s])
    {
        ++w;
        ++s;
    }
    // 더 이상 대응 불가능 하면 왜 while문이 끝났는지 확인
    // 1. 패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야함
    if (w == W.size())
        return ret = (s == S.size());
    // 2. *를 만나서 끝난 경우 : *에 몇 글자를 대응해야할지 재귀 호출하면서 확인한다.
    if (W[w] == '*')
        for (int skip = 0; skip + s <= S.size(); skip++)
            if (matchMemoized(w + 1, s + skip))
                return ret = 1;
    // 이외의 경우에는 모두 대응되지 않는다.
    return ret = 0;
}
void init()
{
    fill_n(cache[0], MAX * MAX, -1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> W >> N;
    for (int i = 0; i < N; i++)
    {
        init();
        cin >> S;
        if (matchMemoized(0, 0))
            cout << S << '\n';
    }

    return 0;
}