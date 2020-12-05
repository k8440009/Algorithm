// 원판 돌리기
// https://www.acmicpc.net/problem/17822
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct INFO
{
	int x, d, k;
};

const int MAX = 50 + 1;
const int dr[4] = {-1,1,0,0};
const int dc[4] = {0,0,-1,1};
int N, M, T;
int idx;
int board[MAX][MAX];
vector <INFO> info;

void rotate() {
	int x = info[idx].x, d = info[idx].d, k = info[idx].k;

	for (int r = x - 1; r < N; r += x) {
		if (d == 0) {
			for (int cnt = 0; cnt < k; cnt++) {
				int tmp = board[r][M - 1];
				for (int c = M - 1; c - 1 >= 0; c--)
					board[r][c] = board[r][c - 1];
				board[r][0] = tmp;
			}
		}
		else{
			for (int cnt = 0; cnt < k; cnt++) {
				int tmp = board[r][0];
				for (int c = 0; c + 1 < M; c++)
					board[r][c] = board[r][c + 1];
				board[r][M - 1] = tmp;
			}
		}
	}
}

void findNum() {
	bool visited[MAX][MAX];
	bool dupN = false;
	fill_n(visited[0], MAX * MAX, 0);

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (board[r][c] == 0)
				continue;

			int data = board[r][c];
			queue <pair<int, int> > q;
			q.push(make_pair(r, c));
			visited[r][c] = 1;

			while (!q.empty()) {
				pair <int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nr = cur.first + dr[dir];
					int nc = cur.second + dc[dir];

					if (nc < 0 || nc >= M) {
						if (nc < 0)
							nc = M - 1;
						else
							nc = 0;
					}
					if (nr < 0 || nr >= N || board[nr][nc] == 0 || visited[nr][nc] || board[nr][nc] != data)
						continue;
					
					dupN = true;
					q.push(make_pair(nr, nc));
					board[nr][nc] = 0;
					board[r][c] = 0;
					visited[nr][nc] = 1;
				}
			}
			
		}
	}

	if (!dupN) {
		int sum = 0;
		int cnt = 0;
		double avg = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (board[r][c] == 0)
					continue;
				sum += board[r][c];
				cnt++;
			}
		}

		avg = (double)sum / (double)cnt;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (board[r][c] == 0)
					continue;

				if ((double)board[r][c] > (double)avg) 
					board[r][c] -= 1;
				else if ((double)board[r][c] < (double)avg)
					board[r][c] += 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> T;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> board[r][c];
	
	info.resize(T);
	for (int i = 0; i < T; i++) 
		cin >> info[i].x >> info[i].d >> info[i].k;

	while (idx != T){
		rotate();
		findNum();
		idx++;
	}

	int sum = 0;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			sum += board[r][c];
	cout << sum;
}