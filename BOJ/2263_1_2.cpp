// 트리의 순회
// https://www.acmicpc.net/problem/2263
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;
int N;
vector <int> in, post;
int location[MAX];

void dfs(int st_in, int ed_in, int st_post, int ed_post){
	if (st_in > ed_in || st_post > ed_post)
		return ;

	int root = post[ed_post];
	cout << root << ' ';
	int pos = location[root];
	int left = pos - st_in;

	dfs(st_in, pos - 1, st_post, st_post + left - 1);
	dfs(pos + 1, ed_in, st_post + left, ed_post - 1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N;
	in.resize(N), post.resize(N);
	for (int i = 0; i < N; i++)
		cin >> in[i];
	for (int i = 0; i < N; i++)
		cin >> post[i];
	for (int i = 0; i < N; i++)
		location[in[i]] = i;
	dfs(0, N - 1, 0, N - 1);
}

/*
https://suhwanc.tistory.com/26
*/