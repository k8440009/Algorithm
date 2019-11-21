// 집합
// https://www.acmicpc.net/problem/11723
#include <bits/stdc++.h>
using namespace std;
// add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
int add(int total, int number)
{
    return total | (1 << number);
}
//remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
int remove(int total, int number)
{
    return total & ~(1 << number);
}
//check x: S에 x가 있으면 1을, 없으면 0을 출력한다.
bool check(int total, int number)
{
    int result = total & (1 << number);
    if (result)
        return true;
    else
        return false;
}
//toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
int toggle(int total, int number)
{
    return total ^ (1 << number);
}
//all: S를 {1, 2, ..., 20} 으로 바꾼다. => (1 << 21) - 1
int all(int number)
{
    return (1 << number) - 1;
}
//empty: S를 공집합으로 바꾼다.
int empty()
{
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int total = 0; // 집합

    while (n--)
    {
        int num;
        string temp;
        cin >> temp;
        // add
        if (temp == "add")
        {
            cin >> num;
            if (!check(total, num))
                total = add(total, num);
        }
        // remove
        else if (temp == "remove")
        {
            cin >> num;
            if (check(total, num))
                total = remove(total, num);
        }
        // check
        else if (temp == "check")
        {
            cin >> num;
            cout << check(total, num) << '\n';
        }
        // toggle
        else if (temp == "toggle")
        {
            cin >> num;
            total = toggle(total, num);
        }
        // all
        else if (temp == "all")
        {
            num = 21;
            total = all(num);
        }
        else
            total = empty();
    }
    return 0;
}