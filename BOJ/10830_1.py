'''
    행렬 제곱
    https://www.acmicpc.net/problem/10830
'''
from sys import stdin


def DivConq(exp):
    c = [[0] * N for _ in range(N)]
    if exp == 1:
        for i in range(N):
            for j in range(N):
                c[i][j] = arr[i][j] % 1000
        return c

    a = [[0] * N for _ in range(N)]

    if exp % 2:  # 홀수
        a = DivConq(exp-1)
        for i in range(N):
            for j in range(N):
                for k in range(N):
                    c[i][j] += a[i][k] * arr[k][j]
                c[i][j] %= 1000
    else:
        a = DivConq(exp//2)
        for i in range(N):
            for j in range(N):
                for k in range(N):
                    c[i][j] += a[i][k] * a[k][j]
                c[i][j] %= 1000
    return c


input = stdin.readline
N, B = map(int, input().strip().split())
arr = [list(map(int, input().strip().split())) for _ in range(N)]
answer = DivConq(B)
for i in range(N):
    for j in range(N):
        print(answer[i][j], end=' ')
    print()
