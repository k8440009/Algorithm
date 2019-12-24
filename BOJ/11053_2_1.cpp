// 가장 긴 증가하는 부분 수열 O(N^2)
// https://www.acmicpc.net/problem/11053
/*
    최적화 문제 동적 계획법
    1. 모든 답을 만들어보고 그 중 최적해의 점수를 반환하는 완전 탐색 알고리즘을 설계합니다
    2. 전체 답의 점수를 반한하는 것이 아니라, 앞으로 남은 선택들에 해당하는 점수만을 반환하도로 부분 문제 정의로 바꿉니다.
    3. 1) 재귀 호출의 입력에 이전의 선택에 관련된 정보가 있다면 꼭 필요한 것만 남기고 줄입니다.
    2) 문제에 최적 부분 구조가 성립 할 경우에는 이전 선택에 관련된 정보를 완전히 없앨 수도 있다. 
    ==> 가능한 중복되는 부분 문제를 많이 만드는 것
    4. 입력이 배열이거나 문자열인 경우 가능하다면 적절한 변환을 통해 메모이제이션을 한다.
    5. 메모이제이션 적용
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000 + 1;
int N;
int cache[MAX], S[MAX];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이 반환
int lis(int start)
{
    int &ret = cache[start + 1];
    if (ret != -1)
        return ret;
    // 항상 S[start]는 있기 때문에 길이 1
    ret = 1;
    for (int next = start + 1; next < N; next++)
    {
        if (start == -1 || S[start] < S[next])
            ret = max(ret, lis(next) + 1);
    }
    return ret;
}
void init()
{
    fill_n(cache, MAX, -1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    init();
    for (int i = 0; i < N; i++)
        cin >> S[i];
    int answer = lis(-1) - 1;
    cout << answer << '\n';
    return 0;
}

/*
완전 탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int N;
vector<int> sub(MAX);
// 백터 반환
int lis(const vector<int> &A)
{
    if (A.empty())
        return 0;
    int ret = 0;
    for (int i = 0; i < A.size(); i++)
    {
        vector<int> B;
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] < A[j])
                B.push_back(A[j]);
            ret = max(ret, 1 + lis(B));
        }
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> sub[i];

    int answer = lis(sub);
    cout << answer + 1 << '\n';

    return 0;
}
*/