// 창고 다각형
// https://www.acmicpc.net/problem/2304
#include <iostream>
using namespace std;

const int MAX = 1000 + 1;
int N;
int arr[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt", "r", stdin);
	cin >> N;
	int start = MAX, end = 0;
	int maxHegiht_y = 0, maxHegiht_x = 0;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a] = b;
		start = min(start, a);
		end = max(end, a);
		if (b > maxHegiht_y)
		{
			maxHegiht_y = max(maxHegiht_y, b);
			maxHegiht_x = a;
		}
	}
	int total = 0;
	int base = 0;
	for (int i = start; i <= maxHegiht_x; i++)
	{
		if (arr[i] > base)
		{
			base = arr[i];
			total += base;
		}
		else
			total += base;
	}
	base = 0;
	for (int i = end; i > maxHegiht_x; i--)
	{
		if (arr[i] > base)
		{
			base = arr[i];
			total += base;
		}
		else
			total += base;
	}
	cout << total;
}