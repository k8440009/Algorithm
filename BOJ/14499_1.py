# 주사위 굴리기
# https://www.acmicpc.net/problem/14499

import sys

dr = [0, 0, -1, 1]
dc = [1, -1, 0, 0]

N, M, Y, X, K = map(int, sys.stdin.readline().split())
board = []
dice = [0, 0, 0, 0, 0, 0]
for i in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))
comd = list(map(int, sys.stdin.readline().split()))


def changeDice(dir):
    temp = 0
    if dir == 0:
        temp = dice[2]
        dice[2] = dice[0]
        dice[0] = dice[3]
        dice[3] = dice[5]
        dice[5] = temp

    elif dir == 1:
        temp = dice[3]
        dice[3] = dice[0]
        dice[0] = dice[2]
        dice[2] = dice[5]
        dice[5] = temp

    elif dir == 2:
        temp = dice[1]
        dice[1] = dice[0]
        dice[0] = dice[4]
        dice[4] = dice[5]
        dice[5] = temp

    else:
        temp = dice[5]
        dice[5] = dice[4]
        dice[4] = dice[0]
        dice[0] = dice[1]
        dice[1] = temp


def solve():
    for i in range(K):
        global Y, X
        # global X
        dir = comd[i] - 1
        nr = Y + dr[dir]
        nc = X + dc[dir]

        if nr < 0 or nr >= N or nc < 0 or nc >= M:
            continue
        changeDice(dir)

        if board[nr][nc] == 0:
            board[nr][nc] = dice[5]
        else:
            dice[5] = board[nr][nc]
            board[nr][nc] = 0

        print(dice[0])

        Y = nr
        X = nc


solve()
