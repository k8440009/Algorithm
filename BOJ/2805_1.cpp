// 나무 자르기
// https://www.acmicpc.net/problem/2805
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int N, M;
vector<int> wood;

int binarySearch(int low, int high)
{

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long sum = 0;
        // 절단 길이 파악
        for (int i = 0; i < wood.size(); i++)
            if (wood[i] > mid)
                sum += (wood[i] - mid);
        // 길이가 큰 경우 톱의 높이를 높인다.
        if (sum >= M)
            low = mid + 1;
        // 길이가 작은 경우 톱의 높이를 낮춘다.
        else
            high = mid - 1;
    }
    return high;
}
void init()
{
    cin >> N >> M;
    wood.resize(N);
    for (int i = 0; i < N; i++)
        cin >> wood[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cout << binarySearch(0, INF); // 나무의 높이를 사용한 이분 탐색
    return 0;
}

/*
    참고
    https://mygumi.tistory.com/331
    
*/