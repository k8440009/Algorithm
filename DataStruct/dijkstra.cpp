/*
    우선 순위 큐(힙 구조)를 이용한 다익스트라 최단거리 알고리즘

    - 참고 -
    https://hsp1116.tistory.com/42
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_VALUE -987654321
int N, M, S;
class Vertex
{
public:
    int index;
    int dist;
    int post = 0;
    Vertex(int index, int dist, int post) : index(index), dist(dist), post(post)
    {
    }
    Vertex(int index) : index(index)
    {
        dist = MAX_VALUE;
    }
    void setDist(int d)
    {
        dist = d;
    }
    bool operator<(const Vertex &v) const
    {
        return dist > v.dist;
    }
    bool operator<(const Vertex &v) const
    {
        return dist > v.dist;
    }
};

class Graph
{
public:
    int n = 0;
    vector<Vertex> vt;
    vector<vector<pair<int, int>>> adj;
    priority_queue<Vertex> pq;
    map<int, pair<int, int>> m;

    void addVertex(int index, int dist)
    {
        vt.push_back(Vertex(index, dist, index));
        n = vt.size();
        adj.resize(n + 1);
    }
    void addAdj(int u, int v, int w)
    {
        adj[u - 1].push_back(make_pair(v, w));
    }
    void setStart(int index)
    {
        vt[index - 1].setDist(0);
        vt[index - 1].post = index;
    }
    void dijkstra(int s)
    {
        vector<int> dist(n - 1 * MAX_VALUE);
        dist[s - 1] = 0;
        setStart(s);
        for (int i = 0; i < n; i++)
            pq.push(vt[i]);
        m.insert(make_pair(s, make_pair(0, -1)));
        while (!pq.empty())
        {
            int index = pq.top().index - 1;
            int cost = -1 * pq.top().dist;
            pq.pop();

            if (dist[index] < cost)
                continue;
            for (int i = 0; i < adj[index].size(); i++)
            {
                int n = adj[index][i].first;
                int v = adj[index][i].second;

                if (dist[n - 1] > dist[index] + v)
                {
                    dist[n - 1] = dist[index] + v;
                    Vertex newVt = Vertex(n, -dist[n - 1], index + 1);
                    pq.push(newVt);
                    m[n] = make_pair(dist[n - 1], index + 1);
                }
            }

            printf("인덱스 별 최단 경로 길이\n");
            for (int i = 0; i < n; i++)
            {
                printf(dist[i] != -1 * MAX_VALUE ? "%d " : "INF ", dist[i]);
            }
        }
    }
};
int main()
{
    return 0;
}