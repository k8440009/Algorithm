'''
    정수 삼각형
    https://www.acmicpc.net/problem/1932

    파이썬은 DP를 구현 할 때 재귀를 사용하지 않는 것이 좋다
'''
from sys import stdin
import sys
input = stdin.readline

N = int(input())
triangle = [[0] * (N+1) for _ in range(N+1)]
cache = [[-1] * (N+1) for _ in range(N + 1)]


for y in range(N):
    tmp = list(map(int, input().split()))
    for x in range(y + 1):
        triangle[y][x] = tmp[x]

cache[0][0] = triangle[0][0]

for y in range(N):
    for x in range(y+1):
        cache[y+1][x] = max(cache[y+1][x], cache[y][x] + triangle[y+1][x])
        cache[y+1][x+1] = max(cache[y+1][x+1], cache[y]
                              [x] + triangle[y+1][x+1])

print(max(cache[-1]))
