// 히스토그램 (분할 정복)
// https://www.acmicpc.net/problem/1725
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> h;
int histogram(int left, int right);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];

    cout << histogram(0, N - 1) << '\n';

    return 0;
}

int histogram(int left, int right)
{
    // 기저 사례 : 판자가 하나밖에 없는 경우
    if (left == right)
        return h[left];
    // [left, mid], [mid + 1, right]의 두 구간으로 문제를 분할
    int mid = (left + right) / 2;
    // divide and conquer
    int result = max(histogram(left, mid), histogram(mid + 1, right));
    // 부분문제 3 : 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
    int low = mid, high = mid + 1;
    int height = min(h[low], h[high]);
    // [mid, mid + 1]만 포함하는 너비 2인 사각형을 고려한다.
    result = max(result, height * 2);
    // 사각형이 입력 전체를 덮을 때 까지 확장해 나간다.
    while (left < low || high < right)
    {
        // 항상 높이가 더 높은 쪽으로 확장한다.
        if (high < right && (low == left || h[low - 1] < h[high + 1]))
        {
            high += 1;
            height = min(height, h[high]);
        }
        else
        {
            low -= 1;
            height = min(height, h[low]);
        }
        // 확장 한 이후 사각형 넓이
        result = max(result, height * (high - low + 1));
    }

    return result;
}