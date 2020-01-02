'''
    보물섬
    https://www.acmicpc.net/problem/2589
'''
import sys
from collections import deque
input = sys.stdin.readline
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
N, M = map(int, input().split())
board = [list(input().strip()) for _ in range(N)]


def BFS(row, col):

    Q = deque()
    Q.append((row, col, 0))
    visited = [[0] * M for _ in range(N)]
    visited[row][col] = True

    cnt = 0
    while Q:
        for _ in range(len(Q)):
            y, x, length = Q.popleft()
            for dy, dx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                ny, nx, nextLength = y + dy, x + dx, length + 1
                if 0 <= ny < N and 0 <= nx < M and not visited[ny][nx] and board[ny][nx] == 'L':
                    visited[ny][nx] = True
                    cnt = max(cnt, nextLength)
                    Q.append((ny, nx, nextLength))
    return cnt


ans = 0
for y in range(N):
    for x in range(M):
        if board[y][x] == 'L':
            ans = max(ans, BFS(y, x))
print(ans)
'''
    참고
    deque : https://dongdongfather.tistory.com/72
'''
