# 초콜릿 자르기 (점화식)
# https://www.acmicpc.net/problem/2163
import sys
N,M = map(int, sys.stdin.readline().split())
print (N - 1 + (M - 1) * N)