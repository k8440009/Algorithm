'''
    외판원 순회 2
    https://www.acmicpc.net/problem/10971
'''
import sys
input = sys.stdin.readline
# 초기화
N = int(input())
INF = 987654321
answer = INF
dist = [list(map(int, input().split())) for _ in range(N)]
for y in range(N):
    for x in range(N):
        if dist[y][x] == 0:
            dist[y][x] = INF


def shortestPath(path, visited, currentLength):
    global answer
    if currentLength >= answer:  # 백 트래킹
        return INF
    if len(path) == N:
        return currentLength + dist[path[-1]][path[0]]

    ret = INF
    here = path[-1]
    for next in range(N):
        if visited[next]:
            continue
        path.append(next)
        visited[next] = True
        cand = min(ret, shortestPath(path, visited,
                                     currentLength + dist[here][next]))
        ret = min(ret, cand)
        path.pop()
        visited[next] = False
    return ret


path = []
visited = [False] * N

for start in range(N):
    path.append(start)
    visited[start] = True
    answer = min(answer, shortestPath(path, visited, 0))
    path.pop()
    visited[start] = False
print(answer)
