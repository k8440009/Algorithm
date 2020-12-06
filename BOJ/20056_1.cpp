// 마법사 상어와 파이어볼
//  https://www.acmicpc.net/problem/20056
#include <iostream>
#include <vector>
using namespace std;

struct FIREBALL{
	int r, c, d;
	int m, s;
	int ballCnt;
	bool flag;
};

const int MAX = 50 + 1;
const int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K;
vector <FIREBALL> board[MAX][MAX];
vector <FIREBALL> nextBoard[MAX][MAX];

bool checkDir(int cur, int next){
	// 짝
	if (cur % 2 == 0){
		if (next % 2 == 0)
			return true;
		return false;
	}
	// 홀
	if (next % 2 == 1)
		return true;
	return false;
}

void moveFireBall(){
	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++){
			if (board[r][c].size() > 0){
				for (int i = 0; i < board[r][c].size(); i++){
					FIREBALL cur = board[r][c][i];

					int moveCnt = cur.s % N;
					int nr = cur.r, nc = cur.c;
					while(moveCnt--){
						nr = cur.r + dr[cur.d];
						nc = cur.c + dc[cur.d];
						
						if (nr < 0 || nr >= N){
							if (nr < 0)
								nr = N - 1;
							else
								nr = 0;
						}
						if (nc < 0 || nc >= N){
							if (nc < 0)
								nc = N - 1;
							else
								nc = 0;
						}
						cur.r = nr;
						cur.c = nc;
					}
					// 넣기
					if (nextBoard[nr][nc].size() > 0){
						FIREBALL &next = nextBoard[nr][nc][0];

						next.m += cur.m;
						next.s += cur.s;
						next.ballCnt += 1;
						if (!checkDir(cur.d, next.d))
							next.flag = false;
					}
					else
					{
						cur.flag = true;
						cur.ballCnt = 1;
						nextBoard[nr][nc].push_back(cur);
					}
				}
				

			}
		}
	}

	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++){
			board[r][c].clear();
			board[r][c] = nextBoard[r][c];
			nextBoard[r][c].clear();
		}
	}
}

void divideFireBall(){
	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++){
			if (board[r][c].size() > 0 && board[r][c][0].ballCnt > 1){
				int fireM = board[r][c][0].m / 5;
				int fireS = board[r][c][0].s / board[r][c][0].ballCnt;

				FIREBALL cur = board[r][c][0];
				board[r][c].clear();
				if (fireM > 0){
					int d;
					cur.flag ? d = 0 : d = 1;
					for (; d < 8; d += 2){
						FIREBALL tmp;
						tmp.r = r, tmp.c = c, tmp.m = fireM, tmp.s = fireS;
						tmp.d = d;
						board[r][c].push_back(tmp);
					}
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	for (int r = 0; r < M; r++){
		FIREBALL tmp;
		cin >> tmp.r >> tmp.c >>  tmp.m >> tmp.s >> tmp.d;
		tmp.r -=1, tmp.c -=1;
		tmp.ballCnt = 1;
		tmp.flag = true;
		board[tmp.r][tmp.c].push_back(tmp);
	}
	while (K--)
	{
		moveFireBall();
		divideFireBall();
	}
	int answer = 0;

	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++){
			if (board[r][c].size() == 0)
				continue;
			
			for (int i = 0; i < board[r][c].size(); i++){
				answer += board[r][c][i].m;
			}
		}
	}
	cout << answer;
}