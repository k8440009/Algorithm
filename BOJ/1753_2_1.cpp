// 최단경로
// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 20000 + 1;
const int INF = 987654321;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	int V,E,K;
	vector <pair<int,int> > adj[MAX_V];
	int dist[MAX_V];
	bool visited[MAX_V] = {0};
	priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > pq;

	fill_n(dist, MAX_V, INF);
	cin >> V >> E >> K;
	K--;
	for (int i = 0; i < E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back(make_pair(v - 1, w));
	}

	// 다익스트라 알고리즘
	// 아직 방문하지 않은 정점들 중 거리가 가장 짧은 정점을 하나 선택한다.
	// 해당 정점에서 인접하고 아직 방문하지 않은 정점들의 거리를 갱신한다.
	pq.push(make_pair(0, K)); // 시작점에 pq 넣고 시작
	dist[K] = 0; // 시작점으로 거리는 0

	while (!pq.empty()){	// pq가 비면 종료
		int curr;
		do{
			curr = pq.top().second;
			pq.pop();
		}while (!pq.empty() && visited[curr]); // curr이 방문한 정점이면 무시
		// 더 이상 방문할 수 있는 정점이 없으면 종료
		if (visited[curr])
			break;
		
		visited[curr] = true; // 방문
		for (auto &p : adj[curr]){
			int next = p.first, d = p.second;
			// 거리가 갱신 될 경우에 pq에 새로 넣음
			if (dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
	
	for (int i = 0; i < V; i++){
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}