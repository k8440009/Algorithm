// 프린터 큐
// https://www.acmicpc.net/problem/1966
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct INFO{
	int priority;
	int num;
};

int N, M;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++){
		queue <INFO> q;
		vector <int> priority;

		cin >> N >> M;

		for (int i = 0; i < N; i++){
			INFO cur;
			int pr;

			cin >> pr;
			cur.priority = pr;
			cur.num = i;
			q.push(cur);
			priority.push_back(pr);
		}

		sort(priority.begin(), priority.end());
		int sequence = 0;
		while (!q.empty()){
			INFO cur = q.front();
			q.pop();

			int nowPriority = priority.back();
			if (nowPriority == cur.priority){
				++sequence;
				priority.pop_back();
				if (cur.num == M)
					break;
			}
			else
				q.push(cur);
		}
		cout << sequence << '\n';
	} 
}