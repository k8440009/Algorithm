# 괄호 변환
# https://programmers.co.kr/learn/courses/30/lessons/60058

def checkCorrect(s):
	stk = list()
	idx = 0
	while idx < len(s):
		if s[idx] == '(':
			stk.append('(')
		elif s[idx] == ')':
			if len(stk) == 0:
				return False
			else :
				stk.pop()
		idx += 1
	if len(stk) != 0:
		return False
	return True

def sameString(s):
	tmp = ""
	left = 0
	right = 0
	for i in range(len(s)):
		if s[i] == '(':
			tmp += '('
			left += 1
		elif s[i] == ')':
			right += 1
			tmp += ')'

		if left == right and (left != 0 and right != 0):
			return tmp
	return tmp

def change(u, v):
	tmp = "("
	tmp += solve(v)
	tmp += ")"
	st = u[1: len(u) - 1]
	for i in range(len(st)):
		if st[i] == '(':
			tmp += ')'
		else :
			tmp += '('
	return tmp

def solve(st):
	if len(st) == 0:
		return st
	# 균형잡힌 괄호 문자열, u, v로 분리
	u = sameString(st)
	v = st[len(u):]
	# 올바른 괄호 문자열
	if checkCorrect(u):
		return u + solve(v)
	# 아닌 경우
	else :
		return change(u, v)
    
def solution(p):
	answer = ''
	answer = solve(p)
	return answer