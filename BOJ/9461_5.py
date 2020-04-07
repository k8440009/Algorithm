# 파도반 수열
# https://www.acmicpc.net/problem/9461
import sys

dp = [0 for _ in range(102)]

dp[1] = 1
dp[2] = 1
dp[3] = 1

for i in range(4, 101):
	dp[i] = dp[i - 3] + dp[i - 2]

N = int(sys.stdin.readline())

for _ in range(N):
	index = int(sys.stdin.readline())
	print(dp[index])


