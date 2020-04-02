# 무지의 먹방 라이브
# 정확성 O(N^2), 효율성 X (NlogN)
# https://programmers.co.kr/learn/courses/30/lessons/42891
def solution(food_times, k):
	answer = 0
	q = list()
	time = 0
	for i in range(len(food_times)):
		q.append([i + 1, food_times[i]])
	while q:
		if time == k or len(q) == 0:
			break
		cur = q.pop(0)
		index, food = cur[0], cur[1]
		food -= 1
		if food >= 0:
			time += 1
			if food > 0:
				q.append([index, food])
	if time < k:
		answer = -1
	else :
		if len(q) == 0:
			answer = -1
		else :
			cur = q.pop(0)
			answer = cur[0]
	# print(answer)
	return answer

# solution([1,1], 2)
# solution([3,1,2],5)
# solution([1], 5)
