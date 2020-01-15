// 가장 큰 정사각형
// https://www.acmicpc.net/problem/1915
/*
    시간복잡도 O(N^2)
    1. board 배열중에서 1을 만났을 때 (y-1,x-1), (y-1,x), (y,x-1)을 확인해서 값을 증가시킨다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000 + 1;
int board[MAX][MAX];
int cache[MAX][MAX];
int N, M, cnt = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            scanf("%1d", &board[i][j]);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (board[i][j] != 0)
            {
                cache[i][j] = min(cache[i - 1][j - 1], min(cache[i - 1][j], cache[i][j - 1])) + 1;
                cnt = max(cnt, cache[i][j]);
            }
        }
    }
    printf("%d", cnt * cnt);
    return 0;
}

/*	
	참고
	http://mrl.kr/integerscanf/
	https://www.acmicpc.net/board/view/15092
*/