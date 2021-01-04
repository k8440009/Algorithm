// 최단경로
// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
const int MAX_V = 20000;

int V, E, K;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	vector <pair<int,int> > adj[MAX_V];
	vector <int> dist;
	vector <bool> visited;
	priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;

	cin >> V >> E >> K;
	K -= 1;
	dist.resize(V, INF);
	visited.resize(V);
	
	for (int i = 0; i < E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back(make_pair(v - 1, w));
	}
	// 다익스트라
	dist[K] = 0;
	pq.push(make_pair(0, K));
	while(!pq.empty()){
		int curVertex;
	
		while(!pq.empty()){
			curVertex = pq.top().second;
			pq.pop();

			if (!visited[curVertex])
				break;
		}
		// 더 이상 방문할 수 있는 정점이 없으면 종료
		if (visited[curVertex])
			break;

		visited[curVertex] = true;
		for (auto &p : adj[curVertex]){
			int nextVertex = p.first;
			int distance = p.second;
			if (dist[nextVertex] > dist[curVertex] + distance){
				dist[nextVertex] = dist[curVertex] + distance;
				pq.push(make_pair(dist[nextVertex], nextVertex));
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