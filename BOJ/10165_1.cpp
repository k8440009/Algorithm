// 버스 노선
// https://www.acmicpc.net/problem/10165
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

const int MaxSize = 500000;

struct BUS
{
    int start, end, index;
};

int N, M, endPoint;
BUS bus[MaxSize];

bool cmp1(BUS &a, BUS &b)
{
    /*
        시작점이 같으면 끝점이 큰 경우가 앞으로
        시작점이 다르면 시작점이 작은 경우가 앞으로 온다
    */
    return (a.start == b.start) ? (a.end > b.end) : (a.start < b.start);
}

bool cmp2(BUS &a, BUS &b)
{
    /*
        시작점이 같으면 끝점이 큰 경우가 앞으로
        시작점이 다르면 시작점이 작은 경우가 앞으로 온다
    */
    return (a.index < b.index);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> bus[i].start >> bus[i].end;
        bus[i].index = i + 1;

        // 시작점이 끝점 보다 큰 경우
        if (bus[i].start > bus[i].end)
        {
            endPoint = max(endPoint, bus[i].end);
            bus[i].end += N; // 선형으로 표기하기 위해 크기만큼 더해줌
        }
    }

    sort(bus, bus + M, cmp1);

    deque<BUS> dq;
    for (int i = 0; i < M; i++)
    {
        // deque가 비어 있고 deque 끝에 있는 값이 새로운 값 보다 작으면
        if (dq.empty() || dq.back().end < bus[i].end)
        {
            dq.push_back(bus[i]);
        }
    }
    // dq.front().end가 endPoint 보다 커지는 순간 pop_fort 를 할 버스는 존재 하지 않는다.
    while (!dq.empty() && dq.front().end <= endPoint)
    {
        dq.pop_front();
    }

    sort(dq.begin(), dq.end(), cmp2);

    for (auto x : dq)
        cout << x.index << ' ';
}
/*
    참고
    https://www.youtube.com/watch?v=xYkB_geBHAE&t=300s
    https://hyeonstorage.tistory.com/320
*/