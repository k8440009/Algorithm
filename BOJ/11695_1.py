# 구간 합 구하기 4
# https://www.acmicpc.net/problem/11659
import sys
N, M = map(int,sys.stdin.readline().split())
num = list(map(int,sys.stdin.readline().split()))
p_sum = [0 for _ in range(100000 + 1)]
for i in range(N):
    p_sum[i + 1] = p_sum[i] + num[i]
for _ in range(M):
    start, end = map(int,sys.stdin.readline().split())
    print(p_sum[end] - p_sum[start-1])