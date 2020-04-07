// 딱지 놀이
// https://www.acmicpc.net/problem/14696
#include <iostream>
#include <vector>
using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--)
	{
		// a
		int a_state[5], b_state[5];
		fill(a_state, a_state + 5, 0);
		fill(b_state, b_state + 5, 0);
		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			int tmp;
			cin >> tmp;
			a_state[tmp]++;
		}
		cin >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			int tmp;
			cin >> tmp;
			b_state[tmp]++;
		}

		bool flag = 1;
		for (int i = 4; i >= 1; i--)
		{
			if (a_state[i] > b_state[i])
			{
				cout << "A" << '\n';
				flag = 0;
				break;
			}
			else if (a_state[i] < b_state[i])
			{
				cout << "B" << '\n';
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			cout << "D" << '\n';
		}
	}
}