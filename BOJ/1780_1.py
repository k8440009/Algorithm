'''
    종이의 개수
    https://www.acmicpc.net/problem/1780
'''
from sys import stdin


def check(sy, sx, n):
    criteria = paper[sy][sx]
    for y in range(sy, sy + n):
        for x in range(sx, sx + n):
            if paper[y][x] != criteria:
                return False
    return True


def div_conq(sy, sx, n):
    if n == 1:  # 기저 사례
        if paper[sy][sx] == -1:
            answer[0] += 1
        elif paper[sy][sx] == 0:
            answer[1] += 1
        else:
            answer[2] += 1
        return

    flag = check(sy, sx, n)
    if flag:  # 병합
        if paper[sy][sx] == -1:
            answer[0] += 1
        elif paper[sy][sx] == 0:
            answer[1] += 1
        else:
            answer[2] += 1
    else:  # 분할
        size = n//3
        div_conq(sy, sx, size)
        div_conq(sy, sx + size, size)
        div_conq(sy, sx + size * 2, size)

        div_conq(sy + size, sx, size)
        div_conq(sy + size, sx + size, size)
        div_conq(sy + size, sx + size * 2, size)

        div_conq(sy + size * 2, sx, size)
        div_conq(sy + size * 2, sx + size, size)
        div_conq(sy + size * 2, sx + size * 2, size)

    return


input = stdin.readline
answer = [0] * 3
N = int(input())
paper = [list(map(int, input().split())) for _ in range(N)]
div_conq(0, 0, N)
for i in range(3):
    print(answer[i])
