# 초콜릿 자르기 (dp)
# https://www.acmicpc.net/problem/2163
import sys
N,M = map(int, sys.stdin.readline().split())
total = N * M
dp = [-1 for _ in range(total + 2)]
dp[1] = 0
def solve(n):
	if n < 1:
		return 
	if dp[n] != -1:
		return dp[n]
	else:
		m = n // 2
		dp[n] = solve(m) + solve(n - m) + 1
		return dp[n]
solve(total)
print(dp[total])

# 참고
# https://sundries-in-myidea.tistory.com/15