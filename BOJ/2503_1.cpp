// 숫자 야구
// https://www.acmicpc.net/problem/2503
#include <iostream>
#include <string>
using namespace std;
int TC, answer;
const int MAX = 1000;
bool check[MAX];
void init()
{
    for (int i = 123; i <= 999; i++)
    {
        string tmp = to_string(i);
        if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[2] == tmp[0]) // 중복 제거
            continue;
        else if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
            continue;
        check[i] = true;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> TC;
    for (int ts = 0; ts < TC; ts++)
    {
        string point;
        int strike, ball;
        cin >> point >> strike >> ball;
        for (int i = 123; i <= 999; i++)
        {
            // 모든 경우의 수 검색
            string now = to_string(i);
            int strikeCnt = 0, ballCnt = 0;
            // 비교
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    // 위치, 숫자가 같은 경우
                    if (j == k && now[j] == point[k])
                        strikeCnt++;
                    // 숫자가 같은 경우
                    if (j != k && now[j] == point[k])
                        ballCnt++;
                }
            }

            if (strike != strikeCnt || ball != ballCnt)
                check[i] = false;
        }
    }

    for (int i = 123; i <= 999; i++)
        if (check[i])
            answer++;
    cout << answer;

    return 0;
}
/*
    참고
    https://kiung9085.tistory.com/19
*/