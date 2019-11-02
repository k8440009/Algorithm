// 프린터 큐
// https://www.acmicpc.net/problem/1966
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        queue<pair<int, int>> q; // 출력은 queue를 사용
        priority_queue<int> pq;  // 순위는 pq를 사용
        // 문서 수, 목표
        cin >> N >> M;

        // 중요도
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            // 문서번호, 순위
            q.push(make_pair(i, a));
            pq.push(a);
        }

        int cnt = 0; // 순서 체크

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            int index = cur.first;
            int order = cur.second;
            q.pop();
            // 순위랑 같은 경우
            if (pq.top() == order)
            {
                pq.pop();
                cnt += 1;

                if (index == M)
                {
                    cout << cnt << '\n';
                    break;
                }
            }
            else
            {
                q.push(make_pair(index, order));
            }
        }
    }

    return 0;
}

/*
    참고
    http://melonicedlatte.com/algorithm/2018/02/18/230705.html
*/