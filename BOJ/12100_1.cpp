// 2048 (Easy) - 복습 1회차 1시간 10분
#include <iostream>
#include <vector>
using namespace std;

int tmp_board[22][22];
bool visited[22][22];
int N, answer;

void copy_board(int desc[22][22], int src[22][22])
{
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            desc[r][c] = src[r][c];
}

// dir = 0;
void move(int cur_board[22][22], int dir)
{
    fill_n(tmp_board[0], 22 * 22, 0);
    fill_n(visited[0], 22 * 22, 0);
    vector <int> data;
    // 상
    if (dir == 0)
    {
        for(int c = 0; c < N; c++)
        {
            int r = 0, idx = 0;
            while (r < N)
            {
                if (cur_board[r][c] > 0)
                    data.push_back(cur_board[r][c]);
                r++;
            }
            r = 0;
            while (r < N && data.size() != idx)
            {
                if(tmp_board[r][c] == 0)
                {
                    tmp_board[r][c] = data[idx];
                    idx++;
                }
                else
                {
                    if(tmp_board[r][c] == data[idx] && !visited[r][c])
                    {
                        tmp_board[r][c] *= 2;
                        visited[r][c] = 1;
                        idx++;
                    }   
                    else
                        r++;
                }
            }
            data.clear();
        }
    }
    // 하
    else if(dir == 1)
    {
        for(int c = 0; c < N; c++)
        {
            int r = N-1, idx = 0;
            while (r >= 0)
            {
                if (cur_board[r][c] > 0)
                    data.push_back(cur_board[r][c]);
                r--;
            }
            r = N-1;
            while (r >= 0 && data.size() != idx)
            {
                if(tmp_board[r][c] == 0)
                {
                    tmp_board[r][c] = data[idx];
                    idx++;
                }
                else
                {
                    if(tmp_board[r][c] == data[idx] && !visited[r][c])
                    {
                        tmp_board[r][c] *= 2;
                        visited[r][c] = 1;
                        idx++;
                    }
                    else
                        r--;    
                }
            }
            data.clear();
        }
    }
    // 좌
    else if(dir == 2)
    {
        for(int r = 0; r < N; r++)
        {
            int c = 0, idx = 0;
            while (c < N)
            {
                if (cur_board[r][c] > 0)
                    data.push_back(cur_board[r][c]);
                c++;
            }
            c = 0;
            while (c < N && data.size() != idx)
            {
                if(tmp_board[r][c] == 0)
                {
                    tmp_board[r][c] = data[idx];
                    idx++;
                }
                else
                {
                    if(tmp_board[r][c] == data[idx] && !visited[r][c])
                    {
                        tmp_board[r][c] *= 2;
                        visited[r][c] = 1;
                        idx++;
                    }
                    else
                        c++;          
                }
            }
            data.clear();
        }
    }
    // 우
    else
    {
        for(int r = 0; r < N; r++)
        {
            int c = N-1, idx = 0;
            while (c >= 0)
            {
                if (cur_board[r][c] > 0)
                    data.push_back(cur_board[r][c]);
                c--;
            }
            c = N-1;
            while (c >= 0 && data.size() != idx)
            {
                if(tmp_board[r][c] == 0)
                {
                    tmp_board[r][c] = data[idx];
                    idx++;
                }
                else
                {
                    if(tmp_board[r][c] == data[idx] && !visited[r][c])
                    {
                        tmp_board[r][c] *= 2;
                        visited[r][c] = 1;
                        idx++;
                    }
                    else
                        c--;        
                }
            }
            data.clear();
        }
    }

    copy_board(cur_board, tmp_board);
}

int find_max(int cur_board[22][22])
{
    int high = 0;
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            high = cur_board[r][c] > high ? cur_board[r][c] : high;
    return high;
}

void print_board(int cur_board[22][22])
{
    cout << '\n';
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            cout << cur_board[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void dfs(int curr, int cur_board[22][22])
{
    if(curr == 5)
    {
        answer = max(answer, find_max(cur_board));
        return ;
    }

    for(int dir = 0; dir < 4; dir++)
    {
        int next_board[22][22];
        copy_board(next_board, cur_board);
        move(next_board, dir);
        dfs(curr + 1, next_board);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int board[22][22];
    answer = 0;
    
    cin >> N;
    for(int r = 0; r < N; r++)
        for(int c = 0; c < N; c++)
            cin >> board[r][c];
    dfs(0, board);
    cout << answer << '\n';
}