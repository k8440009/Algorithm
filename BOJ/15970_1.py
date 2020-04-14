# 2018 한국정보올림피아드 초등부
# 화살표 그리기
# https://www.acmicpc.net/problem/15970
import sys
N = int(sys.stdin.readline())
total = 0
lst = [[] for _ in range(N + 1)]

for _ in range(N):
	pos, color = map(int, sys.stdin.readline().split())
	lst[color].append(pos)

for i in range(1, N + 1):
	if len(lst[i]) == 0:
		continue
	tmp = sorted(lst[i])
	sum_lst = 0
	size = tmp[1] - tmp[0]
	sum_lst = size
	for pos in range(1, len(tmp)):
		if pos == len(tmp) -1:
			sum_lst += (tmp[pos] - tmp[pos - 1])
		else:
			size = min(tmp[pos] - tmp[pos - 1], tmp[pos + 1] - tmp[pos])
			sum_lst += size
	total += sum_lst
print(total)
	
