// 성곽
// https://www.acmicpc.net/problem/2234
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
int n, m;
int board[50][50];
int d[50][50];
int rooms[50 * 50];

// 서 북 동 남
const int dy[4] = { 0,-1,0,1 };
const int dx[4] = { -1,0,1,0};
int solve(int y, int x, int roomNum)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	d[y][x] = roomNum;
	int cnt = 0;
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		// 방의 넓이 카운트
		cnt++;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 범위 체크
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// 방문 체크
			if (d[ny][nx] != 0) continue;
			// 벽 체크 
			if (board[y][x] & (1 << i)) continue;
			
			// ny,nx는 몇번방인지
			d[ny][nx] = roomNum;
			q.push({ ny,nx });
		}
	}
	return cnt;
}
int main()
{
	cin >> n >> m;
	for(int i=0; i<m; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}

	int num = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			if (d[i][j] == 0) {
				num++;
				// num번방의 넓이는 = solve(i,j,num);
				rooms[num] = solve(i, j, num);
			}
		}
	// 개수 출력
	cout << num << "\n";

	int ret = 0;
	// 가장 큰 넓이 구한다
	for (int i = 1; i <= num; ++i)
	{
		ret = max(ret, rooms[i]);
	}
	cout << ret << "\n";

	// d 에는 각 방의 번호가 적혀있고
	// 합칠수있는 방이라면 합친후 최대값 계산
	ret = 0;
	for(int i=0; i<m; ++i)
		for (int j = 0; j < n; ++j)
		{
			int y = i;
			int x = j;
			for (int k = 0; k < 4; ++k)
			{
				int ny = y + dy[k];
				int nx = x + dx[k];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

				if (d[ny][nx] == d[y][x]) continue;
				// 벽일때 뿌수고 최대값 구해야한다.
				if (board[y][x] & (1 << k)) {
					ret = max(ret, rooms[d[ny][nx]] + rooms[d[y][x]]);
				}
			}
		}
	cout << ret << "\n";
	return 0;
}

// 출처 : https://100100e.tistory.com/178