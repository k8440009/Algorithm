# 뉴스 클러스터링
# https://programmers.co.kr/learn/courses/30/lessons/17677
def union(a, b):
	l = []

	tmp = ""
	for i in range(len(a)):
		data = a[i]
		if tmp != data : 
			tmp = data
			cnt = max(a.count(data), b.count(data))
			while cnt :
				l.append(data)
				cnt -=1
		else : 
			continue
	tmp = ""
	for i in range(len(b)):
		data = b[i]
		if tmp != data :
			if l.count(data) == 0:
				tmp = data
				cnt = b.count(data)
				while cnt :
					l.append(data)
					cnt -=1
		else : 
			continue
	return len(l)


def inter(a, b):
	l = []

	tmp = ""
	for i in range(len(a)):
		data = a[i]
		if tmp != data :
			if a.count(data) > 0 and b.count(data) > 0:
				tmp = data
				cnt = min(a.count(data), b.count(data))
				while cnt :
					l.append(data)
					cnt -=1
		else : 
			continue
	return len(l)

def makeList(str) :
	l = []
	for i in range(len(str) - 1) :
		tmp = str[i] + str[i + 1]
		if str[i] >= 'a' and str[i] <= 'z' and str[i + 1] >= 'a' and str[i + 1] <= 'z' : 
			l.append(tmp)
	return l

def solution(str1, str2):
	answer = 0
	a = []
	b = []

	# 다중집합 구현	
	a = makeList(str1.lower())
	b = makeList(str2.lower())

	a.sort()
	b.sort()
	
	if len(a) == 0 and len(b) == 0:
		answer = 1 * 65536
	else :
		sun = inter(a,b)
		mother = union(a,b)
		answer = int((sun / mother) * 65536)
	print(answer)
	return answer

#solution("FRANCE", "FRENCH")
#solution("aaaabb", "bbbbaa")
#solution("handshake", "shake hands")
#solution("FRENCH", "")