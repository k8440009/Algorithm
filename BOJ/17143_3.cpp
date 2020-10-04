// 낚시왕 3회차 :
// https://www.acmicpc.net/problem/17143
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100 + 1;
const int dr[] = {0,-1,1,0,0};
const int dc[] = {0,0,0,1,-1};

struct SHARK
{
	int r, c;
	int speed, dir, size;
};

vector <SHARK> board[MAX][MAX];
int R, C, M;

int	fishing(int c)
{
	int r = 1, size = 0;

	while (r <= R)
	{
		if (!board[r][c].empty())
		{
			size = board[r][c][0].size;
			board[r][c].pop_back();
			break;
		}
	}
	return (size);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		SHARK tmp;
		cin >> tmp.r >> tmp.c >> tmp.speed >> tmp.dir >> tmp.size;
		board[tmp.r][tmp.c].push_back(tmp);
	}

	int i = 0;
	int answer = 0;
	while (i <= R)
	{
		i++;
		answer += fishing(i);
		// move();
	}
	cout << answer << '\n';
}