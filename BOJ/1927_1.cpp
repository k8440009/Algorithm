// 최소 힙
// https://www.acmicpc.net/problem/1927
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	priority_queue<int, vector<int>, greater<int> > pq;

	cin >> N;
	for (int i = 0; i < N; i++){
		int data;
		cin >> data;
		if (data == 0){
			if (pq.empty())
				cout << 0 << '\n';
			else{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(data);
	}
}