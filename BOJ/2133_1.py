'''
    타일 채우기
    https://www.acmicpc.net/problem/2133
'''
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
MAX = 30 + 1
cache = [-1] * MAX


def tiling(width):
    if width % 2 == 1:
        return 0
    elif width == 0:
        return 1

    if cache[width] != -1:
        return cache[width]

    cache[width] = 3 * tiling(width-2)  # tiling(2) * tiling(width-2)

    i = width-4
    while i >= 0:
        cache[width] += 2 * tiling(i)  # 고유경우 (2) * width[width-4]
        i -= 2
    return cache[width]


# 메인
print(tiling(int(input())))
