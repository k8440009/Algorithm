// 과제 안 내신 분..?
// https://www.acmicpc.net/problem/5597
#include <iostream>
using namespace std;
bool stu[31];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 28; i++)
    {
        int num;
        cin >> num;
        stu[num] = true;
    }

    for (int i = 1; i <= 30; i++)
    {
        if (!stu[i])
            cout << i << '\n';
    }
    return 0;
}