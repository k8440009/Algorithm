// 스티커
// https://www.acmicpc.net/problem/9465
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
int board[2][MAX], cache[MAX][3];
int N;
// 0 : 아무것도 안함
// 1 : 1행 선택
// 2 : 2행 선택
int sticker(int c, int status)
{
	if (c  == N)
		return 0;
	if (cache[c][status] != -1)
		return (cache[c][status]);
	
	int result = sticker(c + 1, 0);
	// 아무것도 선택 안함
	if (status == 0)
	{
		result = max(result, sticker(c + 1, 1) + board[0][c]);
		result = max(result, sticker(c + 1, 2) + board[1][c]);
		cache[c][status] = result;
	}
	// 1행 선택
	else if (status == 1)
	{
		result = max(result, sticker(c + 1, 2) + board[1][c]);
		cache[c][status] = result;
	}
	// 2행 선택
	else if (status == 2)
	{
		result = max(result, sticker(c + 1, 1) + board[0][c]);
		cache[c][status] = result;
	}
	return (result);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		cin >> N;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < N; j++)
				cin >> board[i][j];
		fill_n(cache[0], MAX * 3, -1);
		cout << sticker(0, 0) << '\n';
	}
}