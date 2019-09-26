// 1859 백만장자 프로젝트
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 1000000 + 1;
int N;
int product[MAX];
bool visited[MAX];
vector<int> answer;
/*
    그리디
    https://tallman.tistory.com/12
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase;
    //freopen("input.txt", "r", stdin);
    cin >> testCase;

    for (int tc = 1; tc <= testCase; tc++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> product[i];

        long long result = 0;

        int maxPrice = product[N - 1];
        for (int i = N - 2; i >= 0; i--)
        {
            if (maxPrice > product[i])
                result += maxPrice - product[i];
            else
                maxPrice = product[i];
        }

        cout << "#" << tc << " " << result << '\n';
    }

    return 0;
}