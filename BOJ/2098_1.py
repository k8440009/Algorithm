'''
    외판원 순회
    https://www.acmicpc.net/problem/2098
'''
import sys
# 초기화
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
INF = 987654321
MAX = 16
N = int(input())
cache = [[-1] * (1 << N) for _ in range(N)]
dist = []
for _ in range(N):
    dist.append(list(map(int, input().split())))

# 현재 마을과, 방문한 마을


def shortestPath(current, visited):

    # 전에 계산 된 경우
    if cache[current][visited] != -1:
        return cache[current][visited]

    # 모든 경로를 다 탐색하고 돌아와야하는 경우
    if visited == (1 << N)-1:
        if dist[current][0] != 0:
            return dist[current][0]  # 돌아 올 수 있는 길 존재
        return INF  # 돌아 올 수 있는 길이 없는 경우

    cache[current][visited] = INF
    for next in range(N):
        # 이미 방문 한 마을이거나, 방문 할 수 없는 길이 존재 하지 않는 경우
        if (visited & (1 << next) or dist[current][next] == 0):
            continue
        cache[current][visited] = min(cache[current][visited], shortestPath(
            next, visited | (1 << next)) + dist[current][next])
    return cache[current][visited]


# 메인
print(shortestPath(0, 1))
