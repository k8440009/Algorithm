# 연구소 3
# https://www.acmicpc.net/problem/17142
import sys

dr = [1,-1,0,0]
dc = [0,0,1,-1]

N,M = map(int, sys.stdin.readline().split())
board = []
virus = []
selected = [0 for _ in range(11)]
blank = 0
answer = 987654321
for r in range(N) :
	new_line = list(map(int, sys.stdin.readline().split()))
	for c in range(N):
		if new_line[c] == 0:
			blank +=1
		elif new_line[c] == 2:
			virus.append([r,c])
	board.append(new_line)

def board_Copy(desc, src):
	for r in range(N):
		for c in range(N):
			desc[r][c] = src[r][c]

def bfs():
	global board, selected, blank, answer
	safe = blank
	new_board = [[0 for _ in range(N)] for _ in range(N)]
	visited = [[0 for _ in range(N)] for _ in range(N)]
	time = [[0 for _ in range(N)] for _ in range(N)]
	board_Copy(new_board, board)
	q = list()
	for i in range(len(virus)):
		if selected[i] :
			q.append([0, virus[i][0], virus[i][1]])
			visited[virus[i][0]][virus[i][1]] = 1
			time[virus[i][0]][virus[i][1]] = 0

	while q:
		if safe == 0:
			break
		t,r,c = q.pop(0)
		for dir in range(4):
			nr = r + dr[dir]
			nc = c + dc[dir]
			if nr < 0 or nr >= N or nc < 0 or nc >= N or visited[nr][nc] or new_board[nr][nc] == 1:
				continue
			if new_board[nr][nc] == 0:
				new_board[nr][nc] = 2
				visited[nr][nc] = 1
				time[nr][nc] = t + 1
				safe -=1
				q.append([t + 1, nr, nc])
			elif new_board[nr][nc] == 2:
				visited[nr][nc] = 1
				time[nr][nc] = t + 1
				q.append([t + 1, nr, nc])
	if safe == 0:
		tmp = 0
		for r in range(N):
			for c in range(N):
				if time[r][c] > tmp:
					tmp = time[r][c]
		answer = min(answer, tmp)

			
def dfs(curr, cnt) :
	global selected
	if cnt == M :
		bfs()
		return
	if curr == len(virus):
		return
	
	selected[curr] = 1
	dfs(curr + 1, cnt + 1)
	selected[curr] = 0
	dfs(curr + 1, cnt)

dfs(0, 0)

if blank == 0 :
	print(0)
else : 
	if answer == 987654321 :
		answer = -1
	print(answer)
