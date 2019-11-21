// 집합
// https://www.acmicpc.net/problem/11723
#include <iostream>
#include <string>
using namespace std;
int M;
int add(int total, int n)
{
    return total | (1 << n);
}
int remove(int total, int n)
{
    return total & ~(1 << n);
}
void check(int total, int n)
{
    int result = total & (1 << n);
    if (result)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
int toggle(int total, int n)
{
    return total ^ (1 << n);
}
int all(int n)
{
    return (1 << n) - 1;
}
int empty()
{
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    int total = 0;
    for (int i = 0; i < M; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "all")
            total = all(21);
        else if (cmd == "empty")
            total = empty();
        else
        {
            int x;
            cin >> x;
            if (cmd == "add")
                total = add(total, x);
            else if (cmd == "remove")
                total = remove(total, x);
            else if (cmd == "check")
                check(total, x);
            else if (cmd == "toggle")
                total = toggle(total, x);
        }
    }

    return 0;
}

/*
    참고
    종만북 2
*/