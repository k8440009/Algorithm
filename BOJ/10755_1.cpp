// 공항
// https://www.acmicpc.net/problem/10775
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000 + 1;
int G, P, answer = 0;
vector<int> parent(MAX), treeRank(MAX, 1);
int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}
void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    if (u < v)
        swap(u, v);
    parent[u] = v;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> G >> P;

    for (int i = 1; i <= G; i++)
        parent[i] = i;

    for (int i = 0; i < P; i++)
    {
        int airplane;
        cin >> airplane;

        int docking = find(airplane);
        if (docking == 0)
        {
            break;
        }
        else
        {
            merge(docking, docking - 1);
            answer++;
        }
    }

    cout << answer;

    return 0;
}

/*
    참고
    https://mygumi.tistory.com/245
    https://jaimemin.tistory.com/772
    
    https://mygumi.tistory.com/246
    https://kks227.blog.me/220791837179?Redirect=Log&from=postView
*/