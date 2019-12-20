'''
    1로 만들기 (BottomUp)
    https://www.acmicpc.net/problem/1463

    파이썬은 스택 메모리 제한이 있어서 재귀를 많이 할 것 같다면
    BottomUp 방식으로 짜야한다.

'''
from sys import stdin
MAX = 1000000 + 1
dp = [MAX] * MAX

input = stdin.readline
N = int(input())
dp[1] = 0  # 기저
for i in range(N):
    dp[i+1] = min(dp[i+1], dp[i] + 1)
    if i * 2 < MAX:
        dp[i*2] = min(dp[i*2], dp[i] + 1)
    if i * 3 < MAX:
        dp[i*3] = min(dp[i*3], dp[i] + 1)

print(dp[N])
