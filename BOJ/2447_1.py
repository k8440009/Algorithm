'''
    별 찍기 - 10
    https://www.acmicpc.net/problem/2447
'''
from sys import stdin
input = stdin.readline


def div_conq(sy, sx, n):
    if n == 1:
        board[sy][sx] = "*"
        return
    size = n//3
    div_conq(sy, sx, size)
    div_conq(sy, sx + size, size)
    div_conq(sy, sx + size * 2, size)
    div_conq(sy+size, sx, size)
    div_conq(sy+size, sx + size * 2, size)
    div_conq(sy + size * 2, sx, size)
    div_conq(sy + size * 2, sx + size, size)
    div_conq(sy + size * 2, sx + size * 2, size)


N = int(input().strip())
board = [[" "] * N for _ in range(N)]
div_conq(0, 0, N)
for y in range(N):
    for x in range(N):
        print(board[y][x], end='')
    print()
