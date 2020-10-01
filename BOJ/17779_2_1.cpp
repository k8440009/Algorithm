// 게리맨더링 2
// https://www.acmicpc.net/problem/17779
#include <iostream>
using namespace std;

const int MAX = 20 + 2;

int N, answer = 987654321;
int board[MAX][MAX];
int visited[MAX][MAX];

void print_board()
{
	cout << '\n';
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			cout << visited[r][c] << ' ';
		}
		cout << '\n';
	}
}

int forth(int x, int y, int d1, int d2)
{
	for (int d = 0; d <= d1; d++)
	{
		if (x + d2 + d > N || y + d2 - d < 0 || y + d2 - d > N)
			break;
		visited[x + d2 + d][y + d2 - d] = 5;
	}

	int total = 0;
	for (int r = x + d2 + 1; r <= N; r++)
	{
		for (int c = N; c >= y - d1 + d2; c--)
		{
			if (visited[r][c] == 5)
				break;
			visited[r][c] = 4;
			total += board[r][c];
		}
	}
	return total;
}

int third(int x, int y, int d1, int d2)
{
	for (int d = 0; d <= d2; d++)
	{
		if (x + d1 + d > N || y - d1 + d > N || y - d1 + d < 0)
			break;
		visited[x + d1 + d][y - d1 + d] = 5;
	}

	int total = 0;
	for (int r = x + d1; r <= N; r++)
	{
		for (int c = 1; c < y - d1 + d2; c++)
		{
			if (visited[r][c] == 5)
				break;
			visited[r][c] = 3;
			total += board[r][c];
		}
	}
	return total;
}

int second(int x, int y, int d1, int d2)
{
	for (int d = 0; d <= d2; d++)
	{
		if (x + d > N || y + d > N)
			break;
		visited[x + d][y + d] = 5;
	}

	int total = 0;
	for (int r = 1; r <= x + d2; r++)
	{
		for (int c = N; c > y; c--)
		{
			if (visited[r][c] == 5)
				break;
			visited[r][c] = 2;
			total += board[r][c];
		}
	}
	return total;
}

int first(int x, int y, int d1, int d2)
{
	for (int d = 0; d <= d1; d++)
	{
		if (x + d > N || y - d < 0)
			break;
		visited[x + d][y - d] = 5;
	}
	
	int total = 0;
	for (int r = 1; r < x + d1; r++)
	{
		for (int c = 1; c <= y; c++)
		{
			if (visited[r][c] == 5)
				break;
			visited[r][c] = 1;
			total += board[r][c];
		}
	}
	return (total);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int board_total = 0;
	cin >> N;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
		{
			cin >> board[r][c];
			board_total += board[r][c];
		}
	
	int max_people;
	int min_people;
	
	for (int d1 = 1; d1 <= N; d1++)
	{
		for (int d2 = 1; d2 <= N; d2++)
		{
			for (int x = 1; x < N - d1 - d2; x++)
			{
				for (int y = 1; y < N - d2; y++)
				{
					if (y - d1 >= 1)
					{
						int tmp, five_people;
						five_people = board_total;
						fill_n(visited[0], MAX * MAX, 0);

						tmp = first(x, y, d1, d2);
						max_people = tmp;
						min_people = tmp;
						five_people -= tmp;

						tmp = second(x, y, d1, d2);
						max_people = max(max_people, tmp);
						min_people = min(min_people, tmp);
						five_people -= tmp;

						tmp = third(x, y, d1, d2);
						max_people = max(max_people, tmp);
						min_people = min(min_people, tmp);
						five_people -= tmp;

						tmp = forth(x, y, d1, d2);
						max_people = max(max_people, tmp);
						min_people = min(min_people, tmp);
						five_people -= tmp;

						max_people = max(max_people, five_people);
						min_people = min(min_people, five_people);

						answer = min(answer, max_people - min_people);
					}
				}
			}	
		}
	}
	cout << answer;
}