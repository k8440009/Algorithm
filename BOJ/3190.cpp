// 뱀
// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int n, k, l;
const int MAX = 100;
/*
    위 : 0
    오른쪽 : 1
    아래 : 2
    왼쪽 : 3

    참조 https://sangdo913.tistory.com/164
*/
int direction = 1; // 처음 시작값
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int board[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 지도
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        board[r - 1][c - 1] = 1; // 0,0 에서 부터 시작
    }
    // 명령
    cin >> l;
    vector<pair<int, int>> comm(l);
    for (int i = 0; i < l; i++)
    {
        int t;
        char dir;
        cin >> t >> dir;
        comm[i].first = t;
        if (dir == 'L')
            comm[i].second = -1;
        else
            comm[i].second = 1;
    }
    // 초기화
    int time = 0, index = 0;
    deque<pair<int, int>> snake;
    snake.push_back({0, 0}); // 시작점
    board[0][0] = -1;        // -1 : 뱀, 0 : 아무것도 없음, 1 : 사과

    while (true)
    {
        time++;
        pair<int, int> head = snake.front();

        head.first += dr[direction];
        head.second += dc[direction];

        // 벽 부딫히는 경우 : 종료
        if (head.first < 0 || head.first >= n || head.second < 0 || head.second >= n)
            break;
        // 자기몸에 닫는 경우 : 종료
        else if (board[head.first][head.second] == -1)
            break;
        // 사과인 경우 : 꼬리 안 움직임
        // 다음지역이 빈 공간인 경우 꼬리 이동
        else if (board[head.first][head.second] == 0)
        {
            pair<int, int> tail = snake.back();
            board[tail.first][tail.second] = 0;
            snake.pop_back();
        }
        board[head.first][head.second] = -1;
        snake.push_front(head);
        // 명령
        // 명령 시간이랑 현재시간이랑 같은 경우
        if (comm[index].first == time)
            direction = (4 + direction + comm[index++].second) % 4;
    }

    cout << time << '\n';
    return 0;
}