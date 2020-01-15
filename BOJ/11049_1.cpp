// 행렬 곱셈 순서
// https://www.acmicpc.net/problem/11049
/*
	d[i][j] = i ~ j 행렬 곱 했을 때 필요한 최소 연산 횟수

	초기합
	dp[1][1] = 0
	dp[2][2] = 0
*/
#include <iostream>
using namespace std;
const int MAX = 500 + 1;
const int INF = 987654321;
int N;
int cache[MAX][MAX], matrix[MAX][2];
int solve(int i, int j)
{
    if (i == j)
        return 0;
    if (i + 1 == j)
        return matrix[i][0] * matrix[i][1] * matrix[j][1];

    int &ret = cache[i][j];
    if (ret != -1)
        return ret;
    for (int k = i; k < j; k++)
    {
        int temp = solve(i, k) + solve(k + 1, j) + matrix[i][0] * matrix[k][1] * matrix[j][1];
        if (ret == -1 || ret > temp)
            ret = temp;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    fill_n(cache[0], MAX * MAX, -1);
    for (int i = 1; i <= N; i++)
        cin >> matrix[i][0] >> matrix[i][1]; // 0 은 행, 1은 열
    cout << solve(1, N);
    return 0;
}
/*
	참고
	http://blog.naver.com/PostView.nhn?blogId=hwasub1115&logNo=221252850359
	https://js1jj2sk3.tistory.com/37
	https://zzinnykim.tistory.com/31
	https://lyzqm.blogspot.com/2017/06/11049.html
*/