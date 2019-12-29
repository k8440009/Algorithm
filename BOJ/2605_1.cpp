// 줄 세우기
// https://www.acmicpc.net/problem/2605
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100;
int N;
int numbers[MAX];
vector<int> location(MAX);
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
        int num = numbers[i];
        // 값이 없는 경우
        if (location[num] != 0)
        {
            vector<int>::iterator iter = location.begin();
            // location.insert(num, i + 1);
            location.insert(iter + num, i + 1);
        }
        // 값이 있는 경우
        else
            location[num] = i + 1;
    }

    for (int i = N - 1; i >= 0; i--)
        cout << location[i] << ' ';
    return 0;
}