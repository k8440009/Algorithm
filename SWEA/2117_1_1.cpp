// [모의 SW 역량테스트] 홈 방범 서비스
#include <iostream>
using namespace std;

int N, M;
int board[22][22];
int k_size[12];

bool dist(int a_r, int a_c, int b_r, int b_c, int k)
{
	return abs(a_r - b_r) + abs(a_c - b_c) < k;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("sample_input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		int answer = 1, k = 2;
		cin >> N >> M;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				cin >> board[r][c];
		while (k <= N + 1)
		{
			// 2 시작점
			for (int s_r = 0; s_r < N; s_r++)
			{
				for (int s_c = 0; s_c < N; s_c++)
				{
					int house = 0, cost = k * k + (k - 1) * (k - 1);
					// 집 갯수 확인
					for (int r = 0; r < N; r++)
					{
						for (int c = 0; c < N; c++)
						{
							if (dist(s_r, s_c, r, c, k) && board[r][c] == 1)
								house++;
						}
					}
					if (house * M - cost >= 0)
						answer = max(answer, house);
				}
			}
			k++;
		}
		cout << "#" << ts << ' ' << answer << '\n';
	}
}