# 볼 모으기
# https://www.acmicpc.net/problem/17615

import sys
N = int(sys.stdin.readline())
str = sys.stdin.readline()
ball = []
for i in range(N):
	ball.append(str[i])
answer = 987654321
# 파랑
flag, cnt = 0, 0
for i in reversed(range(N)):
	if ball[i] == 'B':
		flag = 1
	else :
		if flag:
			cnt += 1
answer = min(answer, cnt)

flag, cnt = 0, 0
for i in reversed(range(N)):
	if ball[i] == 'R':
		flag = 1
	else :
		if flag:
			cnt += 1
answer = min(answer, cnt)

flag, cnt = 0, 0
for i in (range(N)):
	if ball[i] == 'B':
		flag = 1
	else :
		if flag:
			cnt += 1
answer = min(answer, cnt)
	
flag, cnt = 0, 0
for i in (range(N)):
	if ball[i] == 'R':
		flag = 1
	else :
		if flag:
			cnt += 1
answer = min(answer, cnt)

print(answer)