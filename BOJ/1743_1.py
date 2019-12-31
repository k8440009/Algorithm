'''
    음식물 피하기
    https://www.acmicpc.net/problem/1743
'''
import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
N, M, K = map(int, input().split())
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
board = [[0] * (M + 1) for _ in range(N + 1)]   # 가로 길이 -> 세로 길이
visited = [[0] * (M + 1) for _ in range(N + 1)]

for _ in range(K):
    r, c = map(int, input().split())
    board[r][c] = 1


def dfs(y, x):
    cnt = 1
    visited[y][x] = True
    for dir in range(4):
        ny = y + dy[dir]
        nx = x + dx[dir]
        if ny < 1 or ny > N or nx < 1 or nx > M or visited[ny][nx]:
            continue
        if board[ny][nx] == 1:
            cnt += dfs(ny, nx)
    return cnt


answer = 0
for y in range(1, N+1):
    for x in range(1, M + 1):
        if board[y][x] == 1 and visited[y][x] == False:
            answer = max(answer, dfs(y, x))
print(answer)
