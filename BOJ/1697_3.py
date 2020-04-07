# 숨바꼭질
# https://www.acmicpc.net/problem/1697

import sys
N,K = map(int, sys.stdin.readline().split())

visited = [0 for _ in range(100001)]
q = list()
q.append([0, N])
visited[N] = 1
answer = 0

while q :
	cur = q.pop(0)
	if cur[1] == K:
		answer = cur[0]
		break

	next = [cur[1] * 2, cur[1] + 1, cur[1] - 1]
	for i in range(len(next)):
		if next[i] < 0 or next[i] >= 100001 or visited[next[i]]:
			continue
		else :
			q.append([cur[0] + 1, next[i]])
			visited[next[i]] = 1

print(answer)