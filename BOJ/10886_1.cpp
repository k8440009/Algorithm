// 0 = not cute / 1 = cute
// https://www.acmicpc.net/problem/10886
#include <iostream>
using namespace std;
int N;
int cute[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 설문조사
    cin >> N;
    // 0 -> cute[0], 1 -> cute[1] : 갯수 체크
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        cute[temp]++;
    }

    if (cute[0] > cute[1])
        cout << "Junhee is not cute!" << '\n';
    else
        cout << "Junhee is cute!" << '\n';

    return 0;
}