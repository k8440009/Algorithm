// 컬러볼
// https://www.acmicpc.net/problem/10800
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200000 + 1;
struct BALL
{
    int color, size, index;
};
int N;
// 사이즈를 오름차순으로 정렬
bool cmp(BALL &a, BALL &b)
{
    return a.size < b.size;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<BALL> a;
    vector<int> answer;
    vector<int> color;
    a.resize(N + 1);
    answer.resize(N + 1);
    color.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int color, size;
        cin >> color >> size;

        BALL ball;
        ball.color = color;
        ball.size = size;
        ball.index = i;

        a[i] = ball;
    }

    sort(a.begin(), a.end(), cmp);
    int total = 0;
    for (int i = 1, j = 1; i <= N; i++)
    {
        for (; a[j].size < a[i].size; j++)
        {
            total += a[j].size;
            color[a[j].color] += a[j].size;
        }

        answer[a[i].index] = total - color[a[i].color];
    }

    for (int i = 1; i <= N; i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}

/*  
    참고
    https://mygumi.tistory.com/273
    https://codersbrunch.blogspot.com/search?q=10800
*/