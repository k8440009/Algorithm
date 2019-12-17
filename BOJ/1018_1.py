'''
    체스판 다시 칠하기
    https://www.acmicpc.net/problem/1018
'''
from sys import stdin


def checkBoard(sy, sx):
    cnt = 0
    for y in range(sy, sy + 8):
        for x in range(sx, sx + 8):
            if y % 2 == x % 2:
                if board[y][x] != 'W':
                    cnt += 1
            else:
                if board[y][x] != 'B':
                    cnt += 1
    return min(cnt, 64-cnt)


M, N = map(int, stdin.readline().split())
board = []
for _ in range(M):
    board.append(stdin.readline().strip())
answer = 64
for y in range(M-7):
    for x in range(N-7):
        answer = min(answer, checkBoard(y, x))
print(answer)
