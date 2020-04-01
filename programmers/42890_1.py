# 후보키
# https://programmers.co.kr/learn/courses/30/lessons/42890

# def dfs(curr, cnt):

checked = [0 for _ in range(9)]
selected = [0 for _ in range(9)]
dataSet = list()
answer = 0

def checkList (data, relation):
	R = len(relation)
	lst = []
	for r in range(R):
		tmp = []
		for lo in data:
			tmp.append(relation[r][lo])
		if lst.count(tmp) != 0:
			return False
		lst.append(tmp)
	# print(lst)
	return True

def checkSet(data):
	global dataSet
	for lst in dataSet:
		if set(lst).issubset(set(data)):
			return False
	return True
def dfs(curr, prev, mx, relation, colSize) :
	if curr == mx:
		global answer, dataSet
		data = []
		for i in range(colSize):
			if selected[i]:
				data.append(i)
		if checkSet(data) and checkList(data, relation):
			answer += 1
			dataSet.append(data)
		return

	for i in range(colSize):
		if checked[i] or selected[i]:
			continue
		if prev > i:
			continue
		selected[i] = 1
		dfs(curr + 1, i, mx, relation, colSize)
		selected[i] = 0

def solution(relation):
	global answer, dataSet
	R = len(relation)
	C = len(relation[0])

	for c in range(C):
		lst = []
		flag = 1
		for r in range(R):
			data = relation[r][c]
			if lst.count(data) != 0:
				flag = 0
				break
			else :
				lst.append(data)
		if flag :
			answer += 1
			checked[c] = 1
			dataSet.append([c])
	# 조합
	for cnt in range(2, len(relation)):
		dfs(0, 0, cnt, relation, C)
	return answer

# solution([["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"], ["400", "con", "computer", "4"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]])
# print(answer)