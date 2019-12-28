// 발전소
// https://www.acmicpc.net/problem/1102
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 16 + 1, INF = 987654321;
int cost[MAX][MAX], cache[MAX][1 << MAX];
int N, P, status = 1 << MAX; // 초기화 필수
string onOff;
// 비트 내 1의 갯수 세기
int countBits(int state)
{
    int cnt = 0;
    while (state)
    {
        cnt += state & 1; // 0 자리 비트 체크
        state >>= 1;      // 한자리씩 비트를 내린다.
    }
    return cnt;
}
int lowestCost(int current, int state)
{
    int &ret = cache[current][state];
    // 발전소가 P 갯수 만큼 켜졌다면 반환
    if (countBits(state) > P)
        return 0;
    // dp
    if (ret != -1)
        return ret;
    // 처음 계산 되는 경우
    ret = INF;
    for (int next = 0; next < N; next++)
    {
        // 꺼진 발전기를 찾는다.
        if (state & (1 << next))
            continue;
        // 발전소를 켰다고 가정
        int nextState = state | (1 << next);
        for (int node = 0; node < N; node++)
        {
            if (nextState & (1 << node)) // 켜진 발전기에서 다시 탐색
                ret = min(ret, lowestCost(node, nextState) + cost[current][next]);
        }
    }
    return ret;
}
void init()
{
    fill_n(cache[0], MAX * (1 << MAX), -1);
    cin >> N;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> cost[y][x];
    cin >> onOff >> P;
    for (int i = 0; i < onOff.size(); i++)
        if (onOff[i] == 'Y')
            status |= (1 << i); // 켜진 발전소를 1비트로 만든다.
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    if (P == 0)
        cout << 0;
    else
    {
        int answer = INF;
        for (int i = 0; i < N; i++)
            if (onOff[i] == 'Y')
                answer = min(answer, lowestCost(i, status));
        if (answer == INF)
            cout << -1;
        else
            cout << answer;
    }

    return 0;
}

/*  
    참고
    https://jaimemin.tistory.com/689
    https://www.geeksforgeeks.org/count-set-bits-in-an-integer/ // 비트에서 1의 갯수 체크
*/