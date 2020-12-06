// 게리맨더링 2
// https://www.acmicpc.net/problem/17779
#include <iostream>
#include <algorithm>

using namespace std;

# define _CRT_SECURE_NO_WARNINGS
const int MAX = 20 + 1;
int N, total, answer = 987654321;
int board[MAX][MAX];
int visited[MAX][MAX];

void line(int s_r, int s_c, int d1, int d2) {

	int r, c;
	r = s_r, c = s_c;
	while (true) {
		if (!(r <= s_r + d1 || c >= s_c - d1))
			break;
		visited[r][c] = 5;
		r++;
		c--;
	}

	r = s_r, c = s_c;
	while (true)
	{
		if (!(r <= s_r + d2 || c <= s_c + d2))
			break;
		visited[r][c] = 5;
		r++;
		c++;
	}

	r = s_r + d1, c = s_c - d1;
	while (true) {
		if (!(r <= s_r + d1 + d2 || c <= s_c - d1 + d2))
			break;
		visited[r][c] = 5;
		r++;
		c++;
	}
	
	r = r = s_r + d2, c = s_c + d2;
	while (true)
	{
		if (!(r <= s_r + d2 + d1 || c >= s_c + d2 - d1))
			break;
		visited[r][c] = 5;
		r++;
		c--;
	}

}

void divide(int s_r, int s_c, int d1, int d2) {

	for (int r = 1; r < s_r + d1; r++) {
		for (int c = 1; c <= s_c; c++) {
			visited[r][c] = 1;
		}
	}
	
	for (int r = 1; r <= s_r + d2; r++) {
		for (int c = s_c + 1; c <= N; c++) {
			visited[r][c] = 2;
		}
	}

	for (int r = s_r + d1; r <= N; r++) {
		for (int c = 1; c < s_c - d1 + d2; c++) {
			visited[r][c] = 3;
		}
	}

	for (int r = s_r + d2 + 1; r <= N; r++) {
		for (int c = s_c - d1 + d2; c <= N; c++) {
			visited[r][c] = 4;
		}
	}

}

void calculate() {

	int maxP = 0, minP = 987654321;
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	int sum5 = 0;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (visited[r][c] == 5 || visited[r][c] == 2 || visited[r][c] == 4)
				break;
			
			if (visited[r][c] == 1)
				sum1 += board[r][c];
			else
				sum3 += board[r][c];

		}

		for (int c = N; c >= 1; c--) {
			if (visited[r][c] == 5 || visited[r][c] == 1 || visited[r][c] == 3)
				break;

			if (visited[r][c] == 2)
				sum2 += board[r][c];
			else
				sum4 += board[r][c];
		}
	}

	sum5 = total - sum1 - sum2 - sum3 - sum4;

	maxP = max(maxP, sum1);
	minP = min(minP, sum1);
	maxP = max(maxP, sum2);
	minP = min(minP, sum2);
	maxP = max(maxP, sum3);
	minP = min(minP, sum3);
	maxP = max(maxP, sum4);
	minP = min(minP, sum4);
	maxP = max(maxP, sum5);
	minP = min(minP, sum5);
	answer = min(answer, maxP - minP);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++) {
			cin >> board[r][c];
			total += board[r][c];
		}

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (r + d1 > N || c - d1 < 1)
						continue;
					if (r + d2 > N || c + d2 > N)
						continue;
					if (r + d1 > N || c - d1 < 1 || r + d1 + d2 > N || c - d1 + d2 > N)
						continue;
					if (r + d2 > N || c + d2 > N || r + d2 + d1 > N || c + d2 - d1 < 1)
						continue;
					divide(r, c, d1, d2);
					line(r, c, d1, d2);
					calculate();
				}
			}
		}
	}
	cout << answer;
	return (0);
}