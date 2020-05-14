# 인간-컴퓨터 상호작용
# https://www.acmicpc.net/problem/16139
import sys
s = sys.stdin.readline()
q = int(sys.stdin.readline())
p_sum = [[0 for _ in range(26)] for _ in range(200000 + 1)]
for index in range(len(s)):
    target = ord(s[index])
    p_sum[index + 1][target] = p_sum[index] + s[index]
for _ in range(q):
    tmp = list(sys.stdin.readline().split())
    a,b,c = ord(tmp[0]), int(tmp[1]), int(tmp[2])