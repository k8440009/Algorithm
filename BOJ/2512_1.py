# 예산
# https://www.acmicpc.net/problem/2512
import sys
N = int(sys.stdin.readline())
budget = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
budget = sorted(budget)
start, end, answer = 0, M, 0

def possible(limit):
    total = 0
    for money in budget:
        total += min(limit, money)
    return total <= M

if possible(budget[-1]):
    print(budget[-1])
else:
    while start + 1 < end:
        mid = (start + end) // 2
        if possible(mid):
            start = mid
        else:
            end = mid
    print(start)

