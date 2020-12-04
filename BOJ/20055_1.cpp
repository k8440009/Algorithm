// 컨베이어 벨트 위의 로봇
// https://www.acmicpc.net/problem/20055
#include <iostream>
using namespace std;

struct BELT{
	int cnt;
	bool robot;
};

const int MAX = 200 + 1;
BELT belt[MAX];
int zeroCnt = 0;

int N, K;

void rotate(){
	BELT tmp;
	tmp = belt[2 * N - 1];
	for (int i = 2 * N - 1; i > 0; i--)
		belt[i] = belt[i - 1];
	belt[0] = tmp;
	if (belt[N - 1].robot)
		belt[N - 1].robot = false;
}

void moveRobot(){
	
	for (int i = N - 1; i >= 0; i--){
		if (belt[i].robot){
			if (belt[i + 1].cnt > 0 && !belt[i + 1].robot){
				belt[i].robot = false;
				belt[i + 1].cnt -= 1;
				belt[i + 1].robot = true;
			}
		}
	}

	if (belt[N - 1].robot)
		belt[N - 1].robot = false;

	if (!belt[0].robot && belt[0].cnt > 0){
		belt[0].robot = true;
		belt[0].cnt -=1;
	}
}

bool maxZero(){
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++){
		if (belt[i].cnt <= 0)
			cnt++;
		if (cnt >= K)
			return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++){
		cin >> belt[i].cnt;
		belt[i].robot = false;
	}
	int state = 0;
	while (true)
	{
		state++;
		rotate();
		moveRobot();
		if (maxZero())
			break;
	}
	cout << state;
}