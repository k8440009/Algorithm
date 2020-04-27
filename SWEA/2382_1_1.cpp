// 2382. [모의 SW 역량테스트] 미생물 격리
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct SWARM
{
	int r, c, cnt, dir;
};

int N, M, K;

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, -1, 1};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("sample_input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		vector<SWARM> board[102][102];
		queue<pair<int, SWARM>> q;
		int time = 0, answer = 0;
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			SWARM tmp;
			cin >> tmp.r >> tmp.c >> tmp.cnt >> tmp.dir;
			q.push(make_pair(time, tmp));
		}

		while (time < M)
		{
			while (!q.empty())
			{
				pair<int, SWARM> cur = q.front();
				q.pop();
				// 1. 다음위치 계산
				SWARM tmp = cur.second;
				int nr = tmp.r + dr[tmp.dir];
				int nc = tmp.c + dc[tmp.dir];
				tmp.r = nr, tmp.c = nc;
				board[nr][nc].push_back(tmp);
			}
			// 1. 약품
			for (int r = 0; r < N; r++)
			{
				for (int c = 0; c < N; c++)
				{
					if (board[r][c].empty())
						continue;
					else
					{
						if (r == 0 || r == N - 1 || c == 0 || c == N - 1)
						{
							int size = board[r][c].size();
							for (int i = 0; i < size; i++)
							{
								board[r][c][i].cnt /= 2;
								if (board[r][c][i].dir == 1)
									board[r][c][i].dir = 2;
								else if (board[r][c][i].dir == 2)
									board[r][c][i].dir = 1;
								else if (board[r][c][i].dir == 3)
									board[r][c][i].dir = 4;
								else if (board[r][c][i].dir == 4)
									board[r][c][i].dir = 3;
							}
						}
						// 군집화 애들 제거
						int size = board[r][c].size();
						if (size > 1)
						{
							int total = 0;
							int max_cnt = 0, max_dir = 0;
							for (int i = 0; i < size; i++)
							{
								int now_cnt = board[r][c][i].cnt, now_dir = board[r][c][i].dir;
								if (now_cnt > max_cnt)
									max_cnt = now_cnt, max_dir = now_dir;
								total += now_cnt;
							}
							SWARM tmp;
							tmp.r = r, tmp.c = c, tmp.cnt = total, tmp.dir = max_dir;
							q.push(make_pair(time + 1, tmp));
						}
						else
						{
							SWARM tmp = board[r][c][0];
							q.push(make_pair(time + 1, tmp));
						}
						board[r][c].clear();
					}
				}
			}
			time++;
		}
		// cout << "test" << '\n';
		while (!q.empty())
		{
			pair<int, SWARM> cur = q.front();
			q.pop();
			SWARM tmp = cur.second;
			//cout << tmp.r << ' ' << tmp.c << ' ' << tmp.cnt << ' ' << '\n';
			answer += tmp.cnt;
		}
		cout << "#" << ts << ' ' << answer << '\n';
	}
}