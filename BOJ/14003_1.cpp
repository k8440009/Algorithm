// 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1000000 + 1, INF = 1000000000 + 1;
int N, S[MAX];
vector<int> sub;
vector<pair<int, int>> subSequence; // 위치와 삽입되는 값 저장
int LIS()
{
    int answer = 0, position = -1;
    sub.push_back(-INF);
    subSequence.push_back(make_pair(-1, -INF));
    for (int i = 0; i < N; i++)
    {
        if (sub.back() < S[i])
        {
            sub.push_back(S[i]);
            answer++;
            position += 1; // 뒤에 삽인 된 경우 위치값 증가 한것
            subSequence.push_back(make_pair(position, S[i]));
        }
        else
        {
            vector<int>::iterator it = lower_bound(sub.begin(), sub.end(), S[i]);
            *it = S[i];
            subSequence.push_back(make_pair(it - sub.begin() - 1, S[i])); // 이전에 만든 수열에서 바뀐 부분의 위치, 값 저장
        }
    }
    return answer;
}
// 재귀를 사용하여 이전 위치 값들 출력
void reconstruct(int size, int location)
{
    int position = size;
    // 뒤에서 부터 체크
    for (int i = location; i >= 0; i--)
    {
        if (subSequence[i].first == -1)
            continue;

        if (subSequence[i].first == position)
        {
            reconstruct(position - 1, i);
            cout << subSequence[i].second << ' ';
            break;
        }
    }
}
void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int answer = LIS();
    cout << answer << '\n';
    reconstruct(answer - 1, subSequence.size() - 1);
    return 0;
}

/*
    참고
    https://jason9319.tistory.com/113
*/