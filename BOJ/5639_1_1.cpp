// 이진 검색 트리 (c언어 스타일의 트리 구현)
// https://www.acmicpc.net/problem/5639
#include <iostream>
#include <vector>
using namespace std;

vector <int> pre;
typedef struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
}node;

node *tree;

node *insert(node *root, int value)
{

	if (root == NULL)
	{
		node *newNode = new node;
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;

		root = newNode;
		return root;
	}
	else
	{
		if (root->value > value)
			root->left = insert(root->left, value);
		else
			root->right = insert(root->right, value);
	}
	return root;
}

void postorder(node *root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->value << '\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	int n;
	while (cin >> n)
		tree = insert(tree, n);
	postorder(tree);
}