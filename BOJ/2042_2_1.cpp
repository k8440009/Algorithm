// 구간 합 구하기
// https://www.acmicpc.net/problem/2042
#include <iostream>
#include <vector>
using namespace std;

struct SegTree{
	int size, start;
	vector <long long> arr;
	SegTree(int n): size(n){
		start = 1;
		while (start < size)
			start *= 2;
		arr.resize(start * 2);
	}
	void construct(){
		for (int i = start - 1; i > 0; i--)
			arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}

	void update(int a, long long b){
		a += start;
		b -= arr[a];	// 차이
		while (a > 0){
			arr[a] += b;
			a /= 2;
		}
	}
	long long sum(int a, int b){
		return sum(a, b, 1, 0, start);
	}
	long long sum(int a, int b, int node, int na, int nb){
		if (b <= na || nb <= a)
			return 0;
		if (a <= na && nb <= b)
			return arr[node];
		int mid = (na + nb) / 2;
		return sum(a, b, node * 2, na, mid) + sum(a, b, node * 2 + 1, mid, nb);
	}
};

int N, M, K;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	SegTree st(N);
	for (int i = 0; i < N; i++)
		cin >> st.arr[st.start + i];
	st.construct();
	for (int i = 0; i < M + K; i++){
		int a;
		cin >> a;
		if (a == 1){
			int b;
			long long c;
			cin >> b >> c;
			st.update(b - 1, c);
		}
		else{
			int b, c;
			cin >> b >> c;
			cout << st.sum(b - 1, c) << '\n';
		}
		
	}
}
// https://github.com/kks227/BOJ/blob/master/2000/2042.cpp