'''
    사탕게임
    https://www.acmicpc.net/problem/3085
'''
from sys import stdin
answer = 0
N = int(stdin.readline())
board = []


def checkCandy(y, x):
    result = 1
    cnt = 1
    # 좌, 우
    for i in range(N-1):
        if board[y][i] == board[y][i+1]:
            cnt += 1
        else:
            result = max(result, cnt)
            cnt = 1
    result = max(result, cnt)
    # 위, 아래
    cnt = 1
    for i in range(N-1):
        if board[i][x] == board[i+1][x]:
            cnt += 1
        else:
            result = max(result, cnt)
            cnt = 1
    result = max(result, cnt)
    return result


for _ in range(N):
    row = list(stdin.readline().strip('\n'))
    board.append(row)

for y in range(N):
    for x in range(N-1):
        board[y][x], board[y][x+1] = board[y][x+1], board[y][x]
        answer = max(answer, checkCandy(y, x), checkCandy(y, x+1))
        board[y][x], board[y][x+1] = board[y][x+1], board[y][x]

        board[x][y], board[x+1][y] = board[x+1][y], board[x][y]
        answer = max(answer, checkCandy(x, y), checkCandy(x+1, y))
        board[x][y], board[x+1][y] = board[x+1][y], board[x][y]

print(answer)
