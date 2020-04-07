# RGB 거리
# https://www.acmicpc.net/problem/1149

import sys
N = int(sys.stdin.readline())
cost = [[0 for _ in range(3)] for _ in range(N)]
for i in range(N):
	r, g, b = map(int, sys.stdin.readline().split())
	cost[i][0], cost[i][1], cost[i][2] = r,g,b

# def dfs(curr, prev, total):
	
# for i in range(3):
#	dfs(0, 0)