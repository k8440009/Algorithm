// 괄호
// https://www.acmicpc.net/problem/9012
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++){
		stack <char> st;
		string brackets;
		bool flag = true;

		cin >> brackets;

		for (auto bracket : brackets){
			if (bracket == '(')
				st.push('(');
			else{
				if (st.size() ==  0 || st.top() != '('){
					flag = false;
					break;
				}
				st.pop();
			}
		}

		if (!flag || st.size() != 0)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}