// 트리의 순회
// https://www.acmicpc.net/problem/2263
#include <iostream>
#include <vector>
using namespace std;
/*
*	in 5 6 8 4 3 1 2 7
*	post 5 8 4 6 2 1 7 3
*
*/
/*
8	
5 6 8 4 3 1 2 7
5 8 4 6 2 1 7 3
*/
int N;
vector <int> in, post;

void dfs(int st_in, int ed_in, int st_post, int ed_post){
	if (st_in > ed_in || st_post > ed_post)
		return ;
	int root = post[ed_post];
	cout << root << ' ';

	for (int i = 0; i < N; i++){
		if (in[i] == root){
			int left = i - st_in;
			dfs(st_in, i - 1, st_post, st_post + left - 1);
			dfs(i + 1, ed_in, st_post + left, ed_post - 1);
			break;
		}
	}
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
	dfs(0, N - 1, 0, N - 1);
}

/*
https://suhwanc.tistory.com/26
*/