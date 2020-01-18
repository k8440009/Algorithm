// LCS 2
// https://www.acmicpc.net/problem/9252
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1000 + 1;
int len1, len2;
char a[MAX], b[MAX];
int cache[MAX][MAX], choose[MAX][MAX];
int lcs(int pos1, int pos2)
{
    // 기저
    if (pos1 == len1 || pos2 == len2)
        return 0;
    int &ret = cache[pos1][pos2];
    if (ret != -1)
        return ret;
    // pos1을 한칸 뒤로,
    ret = lcs(pos1 + 1, pos2);
    // pos2를 한칸 뒤로
    int temp = lcs(pos1, pos2 + 1);
    if (ret < temp)
    {
        ret = temp;
        choose[pos1][pos2] = 1;
    }
    else
        choose[pos1][pos2] = 0;

    if (a[pos1] == b[pos2])
    {
        temp = lcs(pos1 + 1, pos2 + 1) + 1;
        if (ret < temp)
        {
            ret = temp;
            choose[pos1][pos2] = 2;
        }
    }
    return ret;
}
void track(int pos1, int pos2)
{
    // 기저
    if (pos1 == len1 || pos2 == len2)
        return;
    switch (choose[pos1][pos2])
    {
    case 0:
        track(pos1 + 1, pos2);
        break;
    case 1:
        track(pos1, pos2 + 1);
        break;
    default:
        cout << a[pos1];
        track(pos1 + 1, pos2 + 1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    len1 = strlen(a), len2 = strlen(b);
    fill_n(cache[0], MAX * MAX, -1);
    cout << lcs(0, 0) << '\n';
    track(0, 0);
    return 0;
}

/*
	참조
	https://m.blog.naver.com/kks227/220793134705
	https://github.com/kks227/BOJ/blob/master/9200/9252.cpp
*/