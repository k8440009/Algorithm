// 특정한 최단 경로
// https://www.acmicpc.net/problem/1504
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 800;
const int INF = 987654321;

int N, E;
int v1, v2;

vector <int> Djkstra(vector<pair<int, int> > adj[MAX_V], int start, int end){
	vector <int> visitied;
	vector <int> dist;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

	visitied.resize(N);
	dist.resize(N, INF);

	pq.push(make_pair(0, start));
	dist[start] = 0;


	while (!pq.empty()){
		int curr;

		while (!pq.empty()){
			curr = pq.top().second;
			pq.pop();

			if (!visitied[curr])
				break;
		}

		if (visitied[curr])
			break;
		

		for (auto &p : adj[curr]){
			int nextVertex = p.first, distance = p.second;
			if (dist[nextVertex] > dist[curr] + distance){
				dist[nextVertex] = dist[curr] + distance;
				pq.push(make_pair(dist[nextVertex], nextVertex));
			}
		}
	}
	return dist;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);

	vector <pair <int,int> > adj[MAX_V];
	vector <int> result1, result2, result3;

	cin >> N >> E;
	for (int i = 0; i < E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back(make_pair(v - 1 , w));
		adj[v - 1].push_back(make_pair(u - 1 , w));
	}
	cin >> v1 >> v2;
	v1 -= 1, v2 -= 1;
	result1 = Djkstra(adj, 0, N - 1);
	result2 = Djkstra(adj, v1, N - 1);
	result3 = Djkstra(adj, v2, N - 1);

	int answer = INF;
	// 1 -> a - > b -> N
	if (result1[v1] != INF && result2[v2] != INF && result3[N - 1] != INF)
		answer = min(answer, result1[v1] + result2[v2] + result3[N - 1]);
	// 1 -> b -> a -> N
	if (result1[v2] != INF && result3[v1] != INF && result2[N - 1] != INF)
		answer = min(answer, result1[v2] + result3[v1] + result2[N - 1]);
	
	if (answer == INF)
		cout << -1;
	else
		cout << answer;
}