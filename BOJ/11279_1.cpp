// 최대 힙
// https://www.acmicpc.net/problem/11279
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector <int> v;
priority_queue<int> pq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	for (int i = 0; i < N; i++){
		if (v[i] == 0){
			if (pq.size() == 0)
				cout << 0 << '\n';
			else{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(v[i]);
	}
}