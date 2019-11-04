// 집합의 표현
// https://www.acmicpc.net/problem/1717
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000 + 1;
int N, M;
vector<int> parent(MAX);
// x로 들어온 원소의 Root 노드를 반환
int Find(int x)
{
    // Root인 경우 x를 반환
    if (x == parent[x])
        return x;
    // 아니면 Root를 찾아감
    else
    {
        int y = Find(parent[x]);
        parent[x] = y;
        return y;
    }
}
// x원소와 y원소를 합치는 함수로 y의 Root 노드를 x로 한다.
void Union(int x, int y)
{
    /*
        x와 y의 원소가 들어오면
        각각 x에는 들어온 x의 Root 노드 y에는 들어온 y의 Root 노드를 저장해서 비교
        x에 y를 붙이는 방식 -> y의 Root 노드를 x로 결정
    */

    x = Find(x);
    y = Find(y);

    // 부모가 같지 않은 경우
    if (x != y)
        parent[y] = x;

    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    /*
        0 : 합집합, 
        0 a b : a 포함되어 있는 집합과 , b 포함되어 있는 집합 합침
        1 : 확인
        1 a b : a,b 포함되어 있는 지 확인
    */

    // 배열 생성 초기화
    // 처음에는 자기 자신이 부모이다 -> 모두 떨어져 있기 때문
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    int op, a, b;
    while (M--)
    {
        cin >> op >> a >> b;
        // 합집합
        if (op == 0)
            Union(a, b);
        // 포함 여부 확인
        else if (op == 1)
        {
            int parentA = Find(a);
            int parentB = Find(b);

            if (parentA == parentB)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

    return 0;
}