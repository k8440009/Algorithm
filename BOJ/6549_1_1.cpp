// 히스토그램에서 가장 큰 직사각형
// https://www.acmicpc.net/problem/6549
/*
    - 참조 - 

    - 풀이 - 
    https://www.acmicpc.net/blog/view/12
    https://sexycoder.tistory.com/107
*/
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
const int MAX = 100000;
int N;
int a[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        for (int i = 0; i < N; i++)
            cin >> a[i];

        ll answer = 0;
        stack<int> s;

        for (int i = 0; i < N; i++)
        {
            // 스택이 비어있지 않고 현재 막대기의 높이가 스택 맨위의 높이보다 작은 경우
            while (!s.empty() && a[s.top()] > a[i])
            {
                ll height = a[s.top()];
                s.pop();
                // 스택이 비어 있으면 현재 막대기의 index가 너비
                ll width = i;
                // 비어있지 않으면 현재 막대기의 index - 스택 맨위의 index - 1
                if (!s.empty())
                    width = (i - s.top() - 1);

                if (answer < width * height)
                    answer = width * height;
            }
            // 스택이 비어 있거나 현재 막대기의 높이가 스택 맨위 높이보다 큰 경우
            s.push(i);
        }
        // N-1까지 push 한 경우
        while (!s.empty())
        {
            // 스택 맨 위의 높이
            ll height = a[s.top()];
            s.pop();
            // 너비
            ll width = N;
            // 스택이 비어 있지 않은 경우의 너비
            if (!s.empty())
                width = N - s.top() - 1;
            if (answer < width * height)
                answer = width * height;
        }

        cout << answer << '\n';
    }

    return 0;
}
