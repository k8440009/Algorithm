'''
    DFS와 BFS
    https://www.acmicpc.net/problem/1260
'''
import sys
import queue
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
N, M, V = map(int, input().split())
pick = []
visited = [0] * (N + 1)
Graph = [[] * (M + 1) for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    Graph[u].append(v)
    Graph[v].append(u)
for i in range(1, N + 1):
    Graph[i].sort()


def dfs(node):
    visited[node] = True
    pick.append(node)
    for i in range(len(Graph[node])):
        next = Graph[node][i]
        if(visited[next] == False):
            dfs(next)


def bfs(start):
    q = queue.Queue()
    q.put(start)
    visited[start] = True
    pick.append(start)

    while q.empty() == False:
        current = q.get()
        for i in range(len(Graph[current])):
            next = Graph[current][i]
            if(visited[next] == False):
                q.put(next)
                visited[next] = True
                pick.append(next)


dfs(V)
for node in pick:
    print(node, end=" ")
print()
pick.clear()
visited = [0] * (N + 1)
bfs(V)

for node in pick:
    print(node, end=" ")

'''
    참고
    큐 사용법
    https://m.blog.naver.com/PostView.nhn?blogId=dudwo567890&logNo=130165707606&proxyReferer=https%3A%2F%2Fwww.google.com%2F
'''
