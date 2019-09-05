// 톱니바퀴
// https://www.acmicpc.net/problem/14891
#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
/*
    12 : machine[0]
    3 : machine[2]
    9 : machine[6]
*/
vector<deque<int>> machine(5);
bool visited[5]; // 톱니 바퀴 회전 여부
// 현재 index, 방향
void rotate(int index, int direction)
{
    visited[index] = true;
    int prev = index - 1;
    int next = index + 1;
    // 이전 톱니바퀴
    if (prev > 0 && !visited[prev])
    {
        // 다른 방향
        if (machine[prev][2] != machine[index][6])
            rotate(prev, direction * -1);
    }
    // 다음 톱니바퀴
    if (next < 5 && !visited[next])
    {
        if (machine[next][6] != machine[index][2])
            rotate(next, direction * -1);
    }
    // 실행
    // 반시계
    if (direction == -1)
    {
        int tmp = machine[index].front();
        machine[index].pop_front();
        machine[index].push_back(tmp);
    }
    // 시계
    else if (direction == 1)
    {
        int tmp = machine[index].back();
        machine[index].pop_back();
        machine[index].push_front(tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 4; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 8; j++)
            machine[i].push_back(str[j] - '0');
    }

    int k;
    cin >> k;

    vector<pair<int, int>> sequence(k);
    for (int i = 0; i < k; i++)
        cin >> sequence[i].first >> sequence[i].second;

    // 회전
    for (int i = 0; i < k; i++)
    {
        // 회전 번호, 회전 방향
        rotate(sequence[i].first, sequence[i].second);
        fill_n(visited, 5, false);
    }

    int answer = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (machine[i][0] == 1)
            answer += pow(2, i - 1);
    }
    cout << answer << '\n';
    return 0;
}