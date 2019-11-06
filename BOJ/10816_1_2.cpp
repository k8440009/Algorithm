// 숫자 카드 2
// https://www.acmicpc.net/problem/10816
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        cout << upper_bound(a.begin(), a.end(), num) - lower_bound(a.begin(), a.end(), num) << ' ';
    }
}
/*
    참고
    https://jaimemin.tistory.com/993
    https://blockdmask.tistory.com/168
    
*/