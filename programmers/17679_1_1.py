# 프렌즈 4블록
# https://programmers.co.kr/learn/courses/30/lessons/17679
def solution(m, n, tmp):
	answer = 0
	board = []
	for i in range(m):
		board.append(list(tmp[i]))
	while True:
		flag = 1
		visited = [[0 for _ in range(n)] for _ in range(m)]
		# 블록 4개씩 체크
		for r in range(m - 1):
			for c in range(n - 1):
				if board[r][c] != "" and board[r][c] == board[r][c + 1] == board[r + 1][c] == board[r + 1][c + 1]:
					visited[r][c] = 1
					visited[r][c + 1] = 1
					visited[r + 1][c] = 1
					visited[r + 1][c + 1] = 1
					flag = 0
		tmp = [[0 for _ in range(n)] for _ in range(m)]
		for r in range(m) :
			for c in range(n) :
				if visited[r][c] == 1:
					tmp[r][c] = ""
					answer += 1
				else:
					tmp[r][c] = board[r][c]
		board = tmp
		if flag:
			break
		for c in range(n):
			start = m-1
			block = []
			for r in reversed(range(m)):
				if board[r][c] != "":
					start -=1
				else :
					break
			for r in reversed(range(start)):
				if board[r][c] != "":
					block.append(board[r][c])
					board[r][c] = ""
			while True:
				if len(block) == 0:
					break
				board[start][c] = block.pop(0)
				start -= 1
	return answer

# solution(2,3, ["CCC", "CCC", "CCC", "CCC"])
#solution(4,5, ["CCBDE", "AAADE", "AAABF", "CCBBF"])
#solution(6, 6, 	["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"])