// 사다리 타기
// https://www.acmicpc.net/problem/2469
#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000 + 1;
int K, N, q;
string start, finish, answer = "";
string lines[MAX];
void fail(int k)
{
    while (--k)
        cout << 'x';
    cout << '\n';
    exit(EXIT_SUCCESS);
}
void init()
{
    cin >> K >> N; // 사람 수 , 가로줄 수
    cin >> finish;
    for (int i = 0; i < K; i++)
        start += ('A' + i);

    for (int i = 0; i < N; i++)
    {
        cin >> lines[i];
        if (lines[i][0] == '?')
            q = i;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < lines[i].size(); j++)
        {
            char &ch = lines[i][j];
            if (ch == '-')
                swap(start[j], start[j + 1]);
        }
    }

    for (int i = N - 1; i > q; i--)
    {
        for (int j = 0; j < lines[i].size(); j++)
        {
            char &ch = lines[i][j];
            if (ch == '-')
                swap(finish[j], finish[j + 1]);
        }
    }

    for (int i = 0; i < K - 1; i++)
    {
        char up = start[i], down = finish[i];
        if (up != down)
        {
            answer += "-";
            if (i + 2 < K)
            {
                answer += "*";
                i++;
            }
        }
        else
            answer += "*";
    }

    for (int i = 0; i < answer.size(); i++)
        if (answer[i] == '-')
            swap(start[i], start[i + 1]);

    if (start != finish)
        fail(K);
    cout << answer << '\n';

    return 0;
}

/*
    참고
    https://eine.tistory.com/entry/KOI-2010-%EC%B4%88%EB%93%B1%EB%B6%80-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4
    https://kthng.tistory.com/27
*/