// 리모컨
// https://www.acmicpc.net/problem/1107
#include <iostream>
using namespace std;
bool button[10];
int N,M;
// 2 3 4 5 6 7 8 9를 입력 못하는 경우도 고려
const int MAX = 1000000 + 1;
int channel[MAX];
int main(){
    cin >> N >> M; // 목표 채널, 고장난 버튼 갯수
    fill_n(button, 10, 1);
    fill_n(channel, MAX, 1);
    for(int i = 0; i < M; i++){
        int index; 
		cin >> index;
        button[index] = 0;
    }
    // 1. 목표 채널 - 기존 채널
    int cnt = abs(N - 100);
    for(int i = 0; i < MAX; i++){
        string str = to_string(i);
        for(char c : str){
            if(!button[c - '0']){
                channel[i] = 0;
                break;
            }
        }
    }
    
    for(int i = 0; i < MAX; i++){
        if(channel[i]){
            string str = to_string(i);
            int button_cnt = str.size();
            cnt = min(cnt, (abs(N - i) + button_cnt));
        }
    }

    cout << cnt << '\n';
    return 0;
}