'''
    2×n 타일링
    https://www.acmicpc.net/problem/11726
'''
import sys
sys.setrecursionlimit(1000000)  # 재귀 스택
input = sys.stdin.readline
MAX = 1000 + 1
MOD = 10007
cache = [-1] * MAX


def tiling(width):
    if width <= 1:
        return 1
    if cache[width] != -1:
        return cache[width]
    cache[width] = (tiling(width-1) + tiling(width-2)) % MOD
    return cache[width]


# 메인
print(tiling(int(input())))
