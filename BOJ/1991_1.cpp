// 트리 순회
// https://www.acmicpc.net/problem/1991
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 26 + 1;
int N;
vector <vector<int> > tree;

void postorder(int node)
{
	int left = tree[node][0];
	int right = tree[node][1];

	if (left != -1)
		postorder(left);
	if (right != -1)
		postorder(right);
	cout << (char)(node + 'A');
	return ;
}

void inorder(int node)
{
	int left = tree[node][0];
	int right = tree[node][1];

	if (left != -1)
		inorder(left);
	cout << (char)(node + 'A');
	if (right != -1)
		inorder(right);
	return ;
}

void preorder(int node)
{
	int left = tree[node][0];
	int right = tree[node][1];

	cout << (char)(node + 'A');
	if (left != -1)
		preorder(left);
	if (right != -1)
		preorder(right);
	return ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	cin >> N;
	tree.resize(N + 1);
	for (int i = 0; i < N; i++)
	{
		char data;
		cin >> data;
		for (int j = 0; j < 2; j++)
		{
			char tmp;
			cin >> tmp;
			if (tmp == '.')
				tree[int(data - 'A')].push_back(-1);
			else
				tree[int(data - 'A')].push_back(tmp - 'A');
		}
	}
	
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

}