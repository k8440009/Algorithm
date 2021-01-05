// 최소비용 구하기
// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 1000;
const int INF = 987654321;

int N, M, A, B;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	vector <pair<int,int> > adj[MAX_V];
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	vector<int> visited;
	vector<int> dist;

	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back(make_pair(v - 1, w));
	}
	cin >> A >> B;
	A -= 1, B -=1;
	visited.resize(N);
	dist.resize(N, INF);

	// 다익스트라
	pq.push(make_pair(0, A));
	dist[A] = 0;

	while(!pq.empty()){
		int curr;
		while(!pq.empty()){
			curr = pq.top().second;
			pq.pop();

			if (!visited[curr])
				break;
		}

		if (visited[curr])
			break;
		
		for (auto &p : adj[curr]){
			int nextVertex = p.first;
			int distance = p.second;
			if (dist[nextVertex] > dist[curr] + distance){
				dist[nextVertex] = dist[curr] + distance;
				pq.push(make_pair(dist[nextVertex], nextVertex));
			}
		}
	}
	cout << dist[B];
}