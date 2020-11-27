// 빗물
// https://www.acmicpc.net/problem/14719
#include <iostream>
using namespace std;

const int MAX = 500 + 1;

int H, W;
int arr[MAX];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> H >> W;
	int maxH = 0, mid = 0;
	for (int i = 0; i < W; i++)
	{
		cin >> arr[i];
		if (arr[i] > maxH)
		{
			maxH = arr[i];
			mid = i;
		}
	}
	int total = 0;
	int base = 0;
	for (int i = 0; i < mid; i++)
	{
		if (arr[i] > base)
			base = arr[i];
		else
			total += (base - arr[i]);
	}
	base = 0;
	for (int i = W - 1; i > mid; i--)
	{
		if (arr[i] > base)
			base = arr[i];
		else
			total += (base - arr[i]);
	}
	cout << total;
}