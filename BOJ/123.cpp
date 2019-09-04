#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

// 사과를 먹으면 뱀의 길이가 늘어난다 .
// 벽 또는 자기 자신의 몸과 부딪히면 게임 종료
// NxN 보드 ( 보드의 상하좌우 끝에는 벽 )
// 게임 시작 시 뱀은 맨위 맨 좌측 . 길이 1 . 처음 방향 : 오른쪽

// 1. 몸 길이를 늘려 머리를 다음칸에 위치
// 2. 이동한 칸에 사과 o : 사과는 사라지고 꼬리는 움직이지 않는다 .
// 3. 이동한 칸에 사과 x : 몸길이를 줄여 꼬리가 위치한 칸을 비워준다. ( 몸길이 변화 x )

// L : 왼쪽 . D : 오른쪽

// 몇초안에 게임이 끝나는지

int N, apple_num, L;
int dir_state;

int board[101][101]; // 보드의 크기

int head_r, head_c;
int tail_r, tail_c;

deque<pair<int, char>> dir_vec; // 방향 전환 정보 저장

deque<pair<int, int>> snake;

// 상. 우. 하. 좌
int dir_r[4] = {-1, 0, 1, 0};
int dir_c[4] = {0, 1, 0, -1};

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int time = 0;
    bool stop = false;

    cin >> N >> apple_num;

    for (int i = 0; i < apple_num; i++)
    {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    } // 사과 위치 정보 표시

    head_r = 1, head_c = 1, tail_r = 1, tail_c = 1; // 초기위치 맨 좌측 . 맨 위
    dir_state = 1;                                  // 처음 우측 방향

    snake.push_back({1, 1});

    cin >> L; // 방향 전환 횟수

    for (int i = 0; i < L; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        dir_vec.push_back({a, b});
    }

    while (true)
    {
        time++;

        head_r += dir_r[dir_state], head_c += dir_c[dir_state]; // 머리 위치 먼저 이동

        if (head_r < 1 || head_c < 1 || head_r > N || head_c > N) // 보드 밖에 이탈시
            break;

        for (int i = 0; i < snake.size(); i++)
        { // 자기 몸과 부딪힐 경우
            if (head_r == snake[i].first && head_c == snake[i].second)
                stop = true;
            break;
        }
        if (stop)
            break; // 종료

        snake.push_back({head_r, head_c});

        if (board[head_r][head_c] == 1)
        {                              // 사과 있을 경우
            board[head_r][head_c] = 0; // 사과 제거
        }
        else
        {                      // 사과 없을 경우
            snake.pop_front(); // 꼬리부분 제거
        }

        if (!dir_vec.empty())
        { // 방향전환정보가 남았을 경우
            int change_time = dir_vec.front().first;

            if (time == change_time)
            {
                char change_dir = dir_vec.front().second;

                if (dir_state == 0)
                    change_dir == 'L' ? dir_state = 3 : dir_state = 1;
                else if (dir_state == 1)
                    change_dir == 'L' ? dir_state = 0 : dir_state = 2;
                else if (dir_state == 2)
                    change_dir == 'L' ? dir_state = 1 : dir_state = 3;
                else if (dir_state == 3)
                    change_dir == 'L' ? dir_state = 2 : dir_state = 0;

                dir_vec.pop_front();
            }
        }
    }

    cout << time << "\n";
}