// 트리
// https://www.acmicpc.net/problem/4803
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 500;
int N, M, answer;
vector <int> adj[MAX];
int visited[MAX], parent[MAX];
bool cycle;
void dfs(int root){

	if (cycle)
		return ;

	for (auto node : adj[root]){
		if (visited[node]){
			if (node == parent[root])
				continue;
			cycle = true;
			return ;
		}
		
		parent[node] = root; 
		visited[node] = 1;
		dfs(node);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	int tc = 0;
	while (cin >> N >> M)
	{
		++tc;
		if (N == 0 && M == 0)
			break;

		answer = 0;
		fill_n(visited, MAX, 0);
		fill_n(parent, MAX, -1);

		for (int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;

			if (a != b){
				adj[a - 1].push_back(b - 1);
				adj[b - 1].push_back(a - 1);
			}
		}

		for (int i = 0; i < N; i++){
			if (visited[i])
				continue;

			cycle = false;
			visited[i] = 1;
			dfs(i);
			if (!cycle)
				answer += 1;
		}
	

		for (int i = 0; i < N; i++)
			adj[i].clear();

		cout << "Case " << tc << ": ";
		if (answer > 1)
			cout << "A forest of " << answer <<" trees.\n";
		else if (answer == 1)
			cout << "There is one tree.\n";
		else
			cout << "No trees.\n";
	}
	return 0;
}

// 참고
// https://www.acmicpc.net/board/view/19906