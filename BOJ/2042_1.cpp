//	구간 합 구하기
//	https://www.acmicpc.net/problem/2042

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000 + 1;
int N, M, K;
vector<long long> nums, tree;
void update(int node, int left, int right, int targetIndex, long long diff)
{
    if (targetIndex < left || right < targetIndex)
        return;
    else
    {
        tree[node] += diff;
        if (left == right)
            return;
        else
        {
            int mid = (left + right) / 2;
            update(node * 2, left, mid, targetIndex, diff);
            update(node * 2 + 1, mid + 1, right, targetIndex, diff);
        }
    }
}
long long query(int node, int left, int right, int targetLeft, int targetRight)
{
    if (targetRight < left || right < targetLeft)
        return 0;
    // 구간 포함됨
    else if (targetLeft <= left && right <= targetRight)
        return tree[node];
    else
    {
        int mid = (left + right) / 2;
        return query(node * 2, left, mid, targetLeft, targetRight) +
               query(node * 2 + 1, mid + 1, right, targetLeft, targetRight);
    }
}
long long makeTree(int node, int left, int right)
{
    if (left == right)
        return tree[node] = nums[left];
    int mid = (left + right) / 2;
    tree[node] += makeTree(node * 2, left, mid) + makeTree(node * 2 + 1, mid + 1, right);
    return tree[node];
}
void init()
{
    cin >> N >> M >> K;
    nums.resize(MAX);
    for (int i = 1; i <= N; i++)
        cin >> nums[i];
    tree.resize(3 * MAX);
    makeTree(1, 1, N); // node, left, right
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    for (int i = 0; i < M + K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            long long diff = c - nums[b];
            nums[b] = c;
            update(1, 1, N, b, diff);
        }
        else
        {
            cout << query(1, 1, N, b, c) << '\n';
        }
    }
    return 0;
}

/*
참조
https: //fieldanimal.tistory.com/59
*/
