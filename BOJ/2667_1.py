'''
    단지번호붙이기
    https://www.acmicpc.net/problem/2667
'''
import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
N = int(input())
board = [[0] * N for _ in range(N)]
visited = [[0] * N for _ in range(N)]
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
for y in range(N):
    apart = input().strip()
    for x in range(N):
        board[y][x] = int(apart[x])


def dfs(y, x):
    cnt = 1
    visited[y][x] = True
    for dir in range(4):
        ny = y + dy[dir]
        nx = x + dx[dir]
        if ny < 0 or ny >= N or nx < 0 or nx >= N or visited[ny][nx]:
            continue
        if board[ny][nx] == 1:
            cnt += dfs(ny, nx)
    return cnt


answer = []
for y in range(N):
    for x in range(N):
        if board[y][x] == 1 and visited[y][x] == False:
            answer.append(dfs(y, x))
print(len(answer))
for cnt in sorted(answer):
    print(cnt)
