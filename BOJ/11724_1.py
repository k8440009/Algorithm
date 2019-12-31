'''
    연결 요소의 갯수
    https://www.acmicpc.net/problem/11724
'''
import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
N, M = map(int, input().split())
visited = [0] * (N + 1)
graph = [[] * (M) for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)


def dfs(current):
    visited[current] = True
    for i in range(len(graph[current])):
        next = graph[current][i]
        if visited[next] == False:
            dfs(next)


answer = 0
for i in range(1, N + 1):
    if visited[i] == False:
        dfs(i)
        answer += 1
print(answer)
