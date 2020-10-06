// 낚시왕 3회차 refactoring
// https://www.acmicpc.net/problem/17143
// 참고 자료 : https://na982.tistory.com/114?category=145346
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100 + 2;
struct CELL
{
	int speed, dir, size;
};

int R,C,M;

CELL board[2][MAX][MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> M;

	int cur = 0;
	for (int i = 0; i < M; i++)
	{
		int r, c;
		cin >> r >> c;
		cin >> board[cur][r][c].speed >> board[cur][r][c].dir >> board[cur][r][c].size;
	}

	int answer = 0, pos = 0;
	while (pos <= C)
	{
		pos++;
		answer += fishing(pos);
		move(cur);
		cur = (cur + 1) % 2;
	}
	cout << answer;
}