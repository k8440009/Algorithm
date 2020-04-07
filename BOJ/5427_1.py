# 불
# https://www.acmicpc.net/problem/5427
'''
import sys
dr = [1,-1,0,0]
dc = [0,0,1,-1]
TC = int(sys.stdin.readline())
while TC:
	answer = 987654321
	W,H = map(int, sys.stdin.readline().split())
	board = [list(map(str, sys.stdin.readline().split())) for _ in range(H)]
	visited = [[0 for _ in range(W)] for _ in range(H)]
	time = visited = [[0 for _ in range(W)] for _ in range(H)]
	q = list()
	for r in range(H):
		for c in range(W):
			if board[r][c] == '@':
				q.append([0, [r,c], 'p'])
				board[r][c] = '.'
				visited[r][c] = 1
			elif board[r][c] == '*':
				q.append([0,[r,c], 'f'])
				visited[r][c] = 1
	while q:
		if answer != 987654321:
			break
		cur = q.pop(0)
		
		now = cur[0]
		r = cur[1][0]
		c = cur[1][1]
		state = cur[2]
		for dir in range(4):
			nr = r + dr[dir]
			nc = c + dc[dir]
			
			if nr < 0 or nr >= H or nc < 0 or nc >= W:
				if state == 'p':
					answer = time + 1
					break
				continue
			elif visited[nr][nc] or board[nr][nc] == '#':
				continue
			
			if board[nr][nc] == '.':
				if state == 'p':
					board[r][c] = '.'
					board[nr][nc] = '@'
					visited[nr][nc] = 1
					time[nr][nc] = now + 1
				elif state == 'f':
					board[nr][nc] = '*'
					visited[nr][nc] = 1
					time[nr][nc] = now + 1
			elif board[nr][nc] == 'f':

	
	if answer == 987654321:
		print("IMPOSSIBLE")
	else :
		print(answer)
	TC -=1
'''