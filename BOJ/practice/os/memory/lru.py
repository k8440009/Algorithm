# 캐시
# https://programmers.co.kr/learn/courses/30/lessons/17680?language=python3

def find(cache, data) :
	for i in range(len(cache)):
		if cache[i] == data:
			return i
	return -1

def solution(cacheSize, cities):
	answer = 0
	cache = []

	if cacheSize != 0 :
		index = 0
		for i in range(len(cities)):
			data = cities[i].lower()
			index = find(cache, data)
			if index != -1 :
				cache.pop(index)
				cache.append(data)
				answer += 1
			else :
				size = len(cache)
				if size == cacheSize:
					cache.pop(0)
				cache.append(data)
				answer += 5
	else :
		answer = len(cities) * 5
	return answer



# solution(3, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"])