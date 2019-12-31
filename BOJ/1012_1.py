'''
    유기농 배추
    https://www.acmicpc.net/problem/1012
'''
import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
TC = int(input())
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]


def dfs(y, x):
    visited[y][x] = True
    for dir in range(4):
        ny = y + dy[dir]
        nx = x + dx[dir]
        if ny < 0 or ny >= N or nx < 0 or nx >= M or visited[ny][nx]:
            continue
        if board[ny][nx] == 1:
            dfs(ny, nx)


for _ in range(TC):
    M, N, K = map(int, input().split())
    board = [[0]*M for _ in range(N)]
    visited = [[False]*M for _ in range(N)]
    for _ in range(K):
        x, y = map(int, input().split())
        board[y][x] = 1
    cnt = 0
    for y in range(N):
        for x in range(M):
            if board[y][x] == 1 and visited[y][x] == False:
                dfs(y, x)
                cnt += 1
    print(cnt)
