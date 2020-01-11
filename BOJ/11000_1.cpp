// 강의실 배정
// https://www.acmicpc.net/problem/11000
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 200000 + 1;
int N, cnt, endTime;
vector<pair<int, int>> schedule;
priority_queue<int, vector<int>, greater<int>> pq; // 작은것부터 위로
void init()
{
    cin >> N;
    schedule.resize(N);
    int s, e;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> e;
        schedule[i].first = s, schedule[i].second = e;
    }
    sort(schedule.begin(), schedule.end()); // 끝나는 시간을 기준으로 정렬
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    init();

    pq.push(schedule[0].second);

    for (int i = 1; i < N; i++)
    {
        int s = schedule[i].first, e = schedule[i].second;
        // pq.top()에 있는 시간이 시작 시간보다 작거나 같은경우 -> 빼주고 새로운 시간을 넣는다.
        if (pq.top() <= s)
        {
            pq.pop();
            pq.push(e);
        }
        // 강의실이 모두 사용되고 있기 때문에 새로운 강의실을 할당한다.
        else
            pq.push(e);
    }

    cout << pq.size() << '\n';
    return 0;
}
/*
    시도 1
    끝나는 시간으로 정렬

    반례
    6
    1 3
    2 5
    7 8
    4 12
    9 10
    7 11


    시도 2_1
    시작 시간으로 정렬, 일반 배열에 끝나는 시간 저장 -> 시간 초과

    시도 2_2
    끝나는 시간을 pq를 사용하여 저장하면 된다

    참조
    https://j3sung.tistory.com/497
*/