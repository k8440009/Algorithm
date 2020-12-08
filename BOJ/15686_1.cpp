// 치킨 배달
// https://www.acmicpc.net/problem/15686
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50 + 1;
int N, M, answer = 987654321;
int board[MAX][MAX];
int selected[14];
vector <pair<int,int> > house, chicken;

void dfs(int idx, int cnt){
	if (cnt == M){
		vector <pair<int,int> > loc;
		for (int i = 0; i < chicken.size(); i++){
			if (!selected[i])
				continue;
			loc.push_back(make_pair(chicken[i].first, chicken[i].second));
			if (loc.size() == M)
				break;
		}

		int total = 0;
		for (int i = 0; i < house.size(); i++){
			int dist = 987654321;
			for (int j = 0; j < loc.size(); j++){
				dist = min(dist, abs(house[i].first - loc[j].first) + abs(house[i].second - loc[j].second));
			}
			total += dist;
		}
		answer = min(answer, total);
		return ;
	}

	for (int i = idx; i < chicken.size(); i++){
		if (selected[i])
			continue;

		selected[i] = 1;
		dfs(i, cnt + 1);
		selected[i] = 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++){
			cin >> board[r][c];
			if (board[r][c] == 1)
				house.push_back(make_pair(r, c));
			else if (board[r][c] == 2)
				chicken.push_back(make_pair(r, c));
		}
	}
	dfs(0, 0);
	cout << answer;
}