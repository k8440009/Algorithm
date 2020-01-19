// 교환
// https://www.acmicpc.net/problem/1039
/*
    BFS라고 떠올리기 어려운 문제
    string으로 문자 교환
    중복 처리는 set을 사용하여 처리한다.
*/
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
string result = "0"; // 문자열 초기화 주의
int N, K, answer = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << result << '\n';

    cin >> N >> K;

    queue<string> q;
    q.push(to_string(N));

    for (int i = 0; i < K; i++)
    {
        int qSize = q.size();
        set<string> found;
        // string 이기 때문에 배열 사용 불가능
        for (int j = 0; j < qSize; j++)
        {
            string str = q.front();
            q.pop();
            if (found.count(str))
                continue;
            found.insert(str);
            for (int k = 0; k < str.size(); k++)
            {
                for (int l = k + 1; l < str.size(); l++)
                {
                    // k가 제일 큰 자리가 아니거나, 1 자리가 0이 아닌경우
                    if (k > 0 || str[l] != '0')
                    {
                        swap(str[k], str[l]);
                        q.push(str);
                        swap(str[k], str[l]);
                    }
                }
            }
        }
    }

    while (!q.empty())
    {
        result = max(result, q.front());
        q.pop();
    }

    if (result[0] == '0')
        cout << -1 << '\n';
    else
        cout << result;

    return 0;
}
/*
    참조
    http://blog.naver.com/kks227/220613889973
    https://yabmoons.tistory.com/152
*/