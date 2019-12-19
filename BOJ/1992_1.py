'''
    쿼드 트리
    https://www.acmicpc.net/problem/1992
'''
from sys import stdin

answer = ""


def div_conq(sy, sx, n):
    if n == 1:  # 기저
        global answer
        if picture[sy][sx] == 1:
            answer += "1"
        else:
            answer += "0"
        return

    flag = check(sy, sx, n)
    if(flag):
        if picture[sy][sx] == 1:
            answer += "1"
        else:
            answer += "0"
    else:
        answer += "("
        size = n//2
        div_conq(sy, sx, size)
        div_conq(sy, sx + size, size)
        div_conq(sy + size, sx, size)
        div_conq(sy + size, sx + size, size)
        answer += ")"
    return


def check(sy, sx, n):
    for y in range(sy, sy + n):
        for x in range(sx, sx + n):
            if picture[y][x] != picture[sy][sx]:
                return False
    return True


input = stdin.readline
N = int(input().strip())
picture = [list(map(int, input().strip())) for _ in range(N)]
div_conq(0, 0, N)
print(answer)
