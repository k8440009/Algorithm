# 감시
# https://www.acmicpc.net/problem/15683
import sys

rotSize = [4, 2, 4, 4, 1]
N, M = map(int, sys.stdin.readline().split())
answer = 987654321
board = []
cctv = []
for r in range(N):
    new_line = list(map(int, sys.stdin.readline().split()))
    for c in range(M):
        if new_line[c] >= 1 and new_line[c] <= 5:
            cctv.append((r, c, new_line[c] - 1))
    board.append(new_line)


def update(dir, cctv):
    global board
    dir = (dir % 4)
    if dir == 0:
        for c in range(cctv[1] + 1, M):
            if board[cctv[0]][c] == 6:
                break
            board[cctv[0]][c] = -1
    elif dir == 1:
        for r in range(cctv[0]-1, -1, -1):
            if board[r][cctv[1]] == 6:
                break
            board[r][cctv[1]] = -1
    elif dir == 2:
        for c in range(cctv[1] - 1, -1, -1):
            if board[cctv[0]][c] == 6:
                break
            board[cctv[0]][c] = -1
    elif dir == 3:
        for r in range(cctv[0] + 1, N):
            if board[r][cctv[1]] == 6:
                break
            board[r][cctv[1]] = -1


def boardCopy(desc, src):
    for r in range(N):
        for c in range(M):
            desc[r][c] = src[r][c]


def dfs(curr):
    global board
    if curr == len(cctv):
        global answer
        sight_cnt = 0
        for r in range(N):
            for c in range(M):
                if board[r][c] == 0:
                    sight_cnt += 1
        answer = min(answer, sight_cnt)
        return

    backup = [[0 for _ in range(M)] for _ in range(N)]
    cctv_type = cctv[curr][2]
    for dir in range(rotSize[cctv_type]):
        boardCopy(backup, board)
        if cctv_type == 0:
            update(dir, cctv[curr])
        elif cctv_type == 1:
            update(dir, cctv[curr])
            update(dir + 2, cctv[curr])
        elif cctv_type == 2:
            update(dir, cctv[curr])
            update(dir + 1, cctv[curr])
        elif cctv_type == 3:
            update(dir, cctv[curr])
            update(dir + 1, cctv[curr])
            update(dir + 2, cctv[curr])
        elif cctv_type == 4:
            update(dir, cctv[curr])
            update(dir + 1, cctv[curr])
            update(dir + 2, cctv[curr])
            update(dir + 3, cctv[curr])

        dfs(curr + 1)
        boardCopy(board, backup)


dfs(0)
print(answer)
