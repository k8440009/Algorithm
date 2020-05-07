# 나무 자르기
# https://www.acmicpc.net/problem/2805
import sys
N,M = map(int, sys.stdin.readline().split())
tree = list(map(int, sys.stdin.readline().split()))
start, end = 0, 1000000000
while start + 1 < end:
    mid = (start + end) // 2
    total = 0
    for i in range(N):
        if tree[i] > mid:
            total += (tree[i] - mid)
    if total >= M:
        start = mid
    else:
        end = mid
print(start)