// 방 배정하기
// https://www.acmicpc.net/problem/14697
#include <iostream>
using namespace std;

int check(int total, int opr)
{
	int div = total / opr;
	int mod = total % opr;

	return mod;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c, total, answer;
	cin >> a >> b >> c >> total;

	answer = 0;
	for (int i = 0; i <= 50; i++)
	{
		for (int j = 0; j <= 50; j++)
		{
			for (int k = 0; k <= 50; k++)
			{
				answer = a * i + b * j + c * k;
				if (answer == total)
				{
					cout << 1 << '\n';
					return 0;
				}
			}
		}
	}

	cout << 0 << '\n';

	return 0;
}