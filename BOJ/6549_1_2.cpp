// 히스토그램에서 가장 큰 직사각형
// https://www.acmicpc.net/problem/6549
/*
    - 풀이 - 
    https://www.acmicpc.net/blog/view/12

    - 세그먼트 트리 -
    https://www.acmicpc.net/blog/view/9

    - cmath-
    https://blockdmask.tistory.com/112
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000;
int board[MAX];
int N;
/*
    a : 배열 a
    tree : 세그먼트 트리
    node : 세그먼트 트리 노드 번호
    node가 담당하는 합의 범위  start ~ end
*/
void init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = start;
    }
    else
    {
        //
        init(a, tree, node * 2, start, (start + end) / 2);
        //
        init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
        // 왼쪽이 오른쪽 보다 작은 경우
        if (a[tree[node * 2]] <= a[tree[node * 2 + 1]])
            tree[node] = tree[node * 2];
        else
            tree[node] = tree[node * 2] + 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        vector<int> a(N);
        for (int i = 0; i < N; i++)
            cin >> a[i];

        /*
            ceil : 올림함수
            1e-9 : 1e9 = 1*10^9 = 1000000000,

         */
        // 높이
        int h = (int)(ceil(log2(N)) + 1e-9);
        // 2^h
        int treeSize = (1 << (h + 1));
        vector<int> tree(treeSize);
        init(a, tree, 1, 0, N - 1);
    }

    return 0;
}