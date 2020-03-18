# 인구 이동
# https://www.acmicpc.net/problem/16234

import sys

dr = [1, -1, 0, 0]
dc = [0, 0, 1, -1]
N, L, R = map(int, sys.stdin.readline().split())
board = []
visited = [[0 for _ in range(N)] for _ in range(N)]
for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))
g_flag = 0


def bfs(start):
    global g_flag, visited
    q = list()
    q.append(start)
    visited[start[0]][start[1]] = 1
    total = board[start[0]][start[1]]
    alias = []
    while q:
        r, c = q.pop(0)
        for dir in range(4):
            nr = r + dr[dir]
            nc = c + dc[dir]
            people = board[r][c]
            if nr < 0 or nr >= N or nc < 0 or nc >= N or visited[nr][nc]:
                continue
            if abs(people - board[nr][nc]) >= L and abs(people - board[nr][nc]) <= R:
                q.append([nr, nc])
                visited[nr][nc] = 1
                total += board[nr][nc]
                alias.append([nr, nc])
    if len(alias) > 0:
        g_flag = 1
        alias.append(start)
        people = total // len(alias)
        for i in range(len(alias)):
            board[alias[i][0]][alias[i][1]] = people
        alias.clear()


def solve():
    global g_flag, visited
    cnt = 0
    while True:
        g_flag = 0
        visited = [[0 for _ in range(N)] for _ in range(N)]
        for r in range(N):
            for c in range(N):
                if visited[r][c]:
                    continue
                else:
                    bfs([r, c])
        if g_flag == 0:
            break
        else:
            cnt += 1
    print(cnt)


solve()
