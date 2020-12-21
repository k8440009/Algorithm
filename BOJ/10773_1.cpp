// 제로
// https://www.acmicpc.net/problem/10773
#include <iostream>
#include <stack>
using namespace std;

int K;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	int total = 0;
	stack <int> st;
	cin >> K;
	for (int i = 0; i < K; i++){
		int num;
		cin >> num;

		if (num == 0){
			total -= st.top();
			st.pop();
		}
		else{
			st.push(num);
			total += num;
		}
	}
	cout << total;
}