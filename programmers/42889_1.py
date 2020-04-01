# 실패율
# https://programmers.co.kr/learn/courses/30/lessons/42889

def solution(N, stages):
	answer = []
	result = []
	totalSize = len(stages)
	for stage in range(1, N + 1):
		player = stages.count(stage)
		if totalSize != 0:
			fault = player / totalSize
		else :
			fault = 0
		result.append([fault, stage])
		totalSize -= player
	tmp = sorted(result, key=lambda data: (-data[0], data[1]))
	for data in tmp:
		answer.append(data[1])
	#print(answer)
	return answer

# solution(5, [2, 1, 2, 6, 2, 4, 3, 3])
#solution(4, [4, 4, 4, 4, 4])

# https://dailyheumsi.tistory.com/67
# https://wayhome25.github.io/python/2017/03/07/key-function/