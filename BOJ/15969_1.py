# 행복
# https://www.acmicpc.net/problem/15969

import sys

N = int(sys.stdin.readline())
tmp = list(map(int, sys.stdin.readline().split()))
score = sorted(tmp)
print(score[-1] - score[0])