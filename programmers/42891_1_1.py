# 무지의 먹방 라이브
# 정확성 O(N^2), 효율성 X (NlogN)
# https://programmers.co.kr/learn/courses/30/lessons/42891
def solution(food_times, k):
	food = sorted(food_times)
	foodSize = len(food)
	
	time = food[0] * foodSize
	foodSize -=1

	if time > k:
		answer = k
	else :
		flag = 0
		for i in range(1, len(food)):
			time += (food[i] - food[i - 1]) * foodSize
			if time > k:
				flag = 1
				time -= (food[i] - food[i - 1]) * foodSize
				break
			foodSize -=1

		if flag:
			# 중간 종료
			answer = k - time
		else :
			answer = -1
	print(answer)
	return answer

solution([3,1,2], 5)