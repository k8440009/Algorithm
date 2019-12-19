'''
    Z
    https://www.acmicpc.net/problem/1074
'''
from sys import stdin
input = stdin.readline

cnt = 0


def div_conq(sy, sx, n):
    global cnt
    # 기저
    if sy == R and sx == C:
        print(cnt)
        return
    # sy + n > R (참)
    if (sy > R or sy + n <= R) or (sx > C or sx + n <= C):
        cnt += (n * n)
        return

    size = n//2
    div_conq(sy, sx, size)
    div_conq(sy, sx + size, size)
    div_conq(sy + size, sx, size)
    div_conq(sy + size, sx + size, size)


N, R, C = map(int, input().strip().split())
div_conq(0, 0, pow(2, N))
