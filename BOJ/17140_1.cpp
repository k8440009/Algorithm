// 이차원 배열과 연산 1회차 - 60분
// https://www.acmicpc.net/problem/17140
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int board[102][102];
int new_board[102][102];
int num_cnt[101];
int R, C, K;
int answer = INF;

void copy_board(int desc[102][102], int src[102][102], int r_size, int c_size)
{
	for (int r = 1; r <= r_size; r++)
		for (int c = 1; c <= c_size; c++)
			desc[r][c] = src[r][c];
}

void solve()
{
	int r_size = 3, c_size = 3, time = 0;
	while (time <= 100)
	{
		fill_n(new_board[0], 102 * 102, 0);
		if (board[R][C] == K)
		{
			answer = time;
			break;
		}
		// 행연산
		if (r_size >= c_size)
		{
			int max_size = c_size;
			for (int r = 1; r <= r_size; r++)
			{
				fill_n(num_cnt, 101, 0);
				for (int c = 1; c <= c_size; c++)
				{
					if(board[r][c] > 0)
						num_cnt[board[r][c]] += 1;
				}

				vector <int> new_arr;
				vector <pair<int, int>> tmp_arr;
				for (int num = 1; num <= 100; num++)
				{
					if (num_cnt[num] > 0)
						tmp_arr.push_back(make_pair(num_cnt[num], num));	// 등장 횟수, 숫자
				}
				sort(tmp_arr.begin(), tmp_arr.end());
				for (int i = 0; i < tmp_arr.size(); i++)
				{
					new_arr.push_back(tmp_arr[i].second); // 숫자
					new_arr.push_back(tmp_arr[i].first); // 등장 횟수
				}
				for (int i = 0; i < new_arr.size(); i++)
					new_board[r][i + 1] = new_arr[i];
				max_size = max(max_size, int(new_arr.size()));
			}
			c_size = max_size;
			copy_board(board, new_board, r_size, c_size);
		}
		// 열 연산
		else
		{
			int max_size = r_size;
			for (int c = 1; c <= c_size; c++)
			{
				fill_n(num_cnt, 101, 0);
				for (int r = 1; r <= r_size; r++)
				{
					if (board[r][c] > 0)
						num_cnt[board[r][c]] += 1;
				}

				vector <int> new_arr;
				vector <pair<int, int>> tmp_arr;
				for (int num = 1; num <= 100; num++)
				{
					if (num_cnt[num] > 0)
						tmp_arr.push_back(make_pair(num_cnt[num], num));	// 등장 횟수, 숫자
				}
				sort(tmp_arr.begin(), tmp_arr.end());
				for (int i = 0; i < tmp_arr.size(); i++)
				{
					new_arr.push_back(tmp_arr[i].second); // 숫자
					new_arr.push_back(tmp_arr[i].first); // 등장 횟수
				}
				for (int i = 0; i < new_arr.size(); i++)
					new_board[i + 1][c] = new_arr[i];
				max_size = max(max_size, int(new_arr.size()));
			}
			r_size = max_size;
			copy_board(board, new_board, r_size, c_size);
		}
		//print_board(board, r_size, c_size);
		time++;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("sample.txt", "r", stdin);
	cin >> R >> C >> K;
	for (int r = 1; r <= 3; r++)
		for (int c = 1; c <= 3; c++)
			cin >> board[r][c];
	solve();
	if (answer == INF)
		answer = -1;
	cout << answer << '\n';
}