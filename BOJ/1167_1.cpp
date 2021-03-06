// 트리의 지름
// https://www.acmicpc.net/problem/1167
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;
int N, answer;
int visited[MAX];
vector<pair<int,int> > adj[MAX];
pair <int,int> maxDistNode;
void dfs(int root, int dist){

	visited[root] = 1;
	for (auto node : adj[root]){
		if (visited[node.first])
			continue;
		visited[node.first] = 1;
		dfs(node.first, dist + node.second);
		visited[node.first] = 0;
	}

	if (dist > maxDistNode.second){
		maxDistNode.second = dist;
		maxDistNode.first = root;
	}
	visited[root] = 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++){
		int a, b, c;
		cin >> a;
		while (true)
		{
			cin >> b;
			if (b == -1)
				break;
			cin >> c;
			adj[a - 1].push_back(make_pair(b - 1, c));
		}
		
	}

	for (auto node : adj[0]){
		visited[0] = 1;
		dfs(node.first, node.second);
		visited[0] = 0;
	}

	maxDistNode.second = 0;
	dfs(maxDistNode.first, 0);
	cout << maxDistNode.second;
}

/*
*	참고
*	https://koosaga.com/14
*/