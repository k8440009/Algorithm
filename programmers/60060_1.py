# 가사 검색
# https://programmers.co.kr/learn/courses/30/lessons/60060
idx = 0

def back_check(query, word):
	global idx
	for i in reversed(range(len(query))):
		if word[i] != query[i]:
			return False
		else:
			idx = i
	return True
def check(query, word):
	global idx
	for i in range(len(query)):
		if word[i] != query[i]:
			return False
		else:
			idx = i
	return True

def solution(words, queries):
	global idx
	answer = []
	lst = []
	for query in queries:
		if query[0] == '?':
			for i in reversed(range(len(query))):
				if query[i] == '?':
					lst.append([query[:i + 1],query[i + 1:]])
					break
		else:
			for i in range(len(query)):
				if query[i] == '?':
					lst.append([query[:i],query[i:]])
					break
	print(lst)
	for i in range(len(lst)):
		result = 0
		first = lst[i][0]
		second = lst[i][1]
		for word in words:
			if (len(first) + len(second)) == len(word):
				if first[0] != '?':
					if check(first, word):
						if len(second) == len(word[idx:]):
							result += 1
							idx = 0
				else :
					if back_check(second, word):
						if len(first) == len(words[:idx]):
							result += 1
							idx = 0
		answer.append(result)
	print(answer)
	return answer

solution(["frodo", "front", "frost", "frozen", "frame", "kakao"], ["fro??", "????o", "fr???", "fro???", "pro?"])