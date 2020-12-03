// 마법사 상어와 파이어스톰
// https://www.acmicpc.net/problem/20058
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
	3 1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
49 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
1
*/
const int MAX = (1 << 6) + 1;
const int dr[] = {1,-1,0,0};
const int dc[] = {0,0,1,-1};
int board[MAX][MAX], tmpBoard[MAX][MAX];
int visited[MAX][MAX];
int N, Q, length, idx;
vector <int> magic;

void removeIce(){

	int tmp[MAX][MAX];
	for (int r = 0; r < length; r++){
		for (int c = 0; c < length; c++){

			if (board[r][c] == 0){
				tmp[r][c] = 0;
				continue;
			}

			int cnt = 0;
			for (int dir = 0; dir < 4; dir++){
				int nr = r + dr[dir];
				int nc = c + dc[dir];
				
				if (nr < 0 || nr >= length || nc < 0 || nc >= length || board[nr][nc] == 0)
					continue;
				++cnt;
			}
			if (cnt >= 3)
				tmp[r][c] = board[r][c];
			else
				tmp[r][c] = board[r][c] - 1; 
		}
	}
	for (int r = 0; r < length; r++)
		for (int c = 0; c < length; c++)
			board[r][c] = tmp[r][c];
}

void rotate(int s_r, int s_c, int size){
	
	int tmp1[size][size];
	int tmp2[size][size];

	for (int r = 0; r < size ; r++)
		for (int c = 0; c < size; c++)
			tmp1[r][c] = board[s_r + r][s_c + c];
	
	for (int r = 0; r < size; r++)
		for (int c = 0; c < size; c++)
			tmp2[c][size - 1 - r] = tmp1[r][c];
	
	for (int r = 0; r < size ; r++)
		for (int c = 0; c < size; c++)
			board[s_r + r][s_c + c] = tmp2[r][c];
}

void divide(int s_r, int s_c, int size){
	if (size == (1 << magic[idx])){
		rotate(s_r, s_c, size);
		return ;
	}

	int half = size / 2;
	divide(s_r, s_c, half);  // 1면
	divide(s_r, s_c + half, half); // 2면
	divide(s_r + half, s_c, half); // 3면
	divide(s_r + half, s_c + half, half); // 4면
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N >> Q;

	length = 1 << N;
	for (int r = 0; r < length; r++)
		for (int c = 0; c < length; c++)
			cin >> board[r][c];
	magic.resize(Q);
	for (int i = 0; i < Q; i++)
		cin >> magic[i];

	for (int i = 0; i < Q; i++){
		divide(0, 0, 1 << N);
		removeIce();
		idx++;
	}

	int totalIce = 0;
	int totalIceSize = 0;

	for (int r = 0; r < length; r++){
		for (int c = 0; c < length; c++){
			totalIce += board[r][c];
			if (board[r][c] != 0 && !visited[r][c]){
				int cnt = 1;
				queue <pair <int,int> > q;
				q.push(make_pair(r, c));
				visited[r][c] = 1;

				while (!q.empty())
				{
					pair <int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++){
						int nr = cur.first + dr[dir];
						int nc = cur.second + dc[dir];

						if (nr < 0 || nr >= length || nc < 0 || nc >= length || visited[nr][nc] || board[nr][nc] == 0)
							continue;
						
						visited[nr][nc] = 1;
						q.push(make_pair(nr, nc));
						++cnt;
					}
				}
				totalIceSize = max(totalIceSize, cnt);
			}
		}
	}
	cout << totalIce << '\n';
	cout << totalIceSize << '\n';
}

/*
	참고
	https://octorbirth.tistory.com/807
*/