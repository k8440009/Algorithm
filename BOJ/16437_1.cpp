// 양 구출 작전
// https://www.acmicpc.net/problem/16437
#include <iostream>
#include <vector>
using namespace std;

struct ISLAND{
	char t;
	int a, p;
};
const int MAX = 123456 + 1;
int N, answer;
vector <ISLAND> adj;
int visited[MAX];

void dfs(int idx){
	visited[idx] = 1;
	visited[idx] = 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	adj.resize(N);
	for (int i = 1; i < N; i++)
		cin >> adj[i].t >> adj[i].a >> adj[i].p;
	dfs(0);

}