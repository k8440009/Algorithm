// 4013. [모의 SW 역량테스트] 특이한 자석
#include <iostream>
#include <vector>
using namespace std;

int K;
int board[4][8];
vector <pair<int, int>> rot;
int check_rot[4];

void move()
{
	for (int i = 0; i < 4; i++)
	{
		if (check_rot[i] == 1)
		{
			int tmp = board[i][7];
			for (int j = 7; j - 1 >= 0; j--)
				board[i][j] = board[i][j - 1];
			board[i][0] = tmp;
		}
		else if (check_rot[i] == -1)
		{
			int tmp = board[i][0];
			for (int j = 0; j + 1 < 8; j++)
				board[i][j] = board[i][j + 1];
			board[i][7] = tmp;
		}
	}
}

void rotate(int num, int dir)
{
	int basis = num;
	check_rot[basis] = dir;
	for (int i = basis; i + 1 < 4; i++)
	{
		if (board[i][2] != board[i + 1][6])
			check_rot[i + 1] = check_rot[i] * (-1);
		else
			break;
	}

	for (int i = basis; i - 1 >= 0; i--)
	{
		if (board[i][6] != board[i - 1][2])
			check_rot[i - 1] = check_rot[i] * (-1);
		else
			break;
	}
}

void print_board()
{
	cout << '\n';
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			cout << board[r][c] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("sample_input.txt", "r", stdin);
	//freopen("sample_output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		int answer = 0;

		cin >> K;
		rot.resize(K);
		for (int r = 0; r < 4; r++)
			for (int c = 0; c < 8; c++)
				cin >> board[r][c];
		for (int i = 0; i < K; i++)
		{
			cin >> rot[i].first >> rot[i].second;
			rot[i].first -= 1;
		}
		
		for (int i = 0; i < K; i++)
		{
			rotate(rot[i].first, rot[i].second);
			move();
			fill_n(check_rot, 4, 0);
		}
		for (int i = 0; i < 4; i++)
		{
			if (board[i][0] == 1)
				answer += (1 << i);
		}
		cout << "#" << ts << " " << answer << "\n";
		rot.clear();
	}
}