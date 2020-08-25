# 캐시
# https://programmers.co.kr/learn/courses/30/lessons/17680
def solution(cacheSize, cities):
	answer = 0
	cities = [city.lower() for city in cities]
	cache = []
	cache_hit, cache_miss = 1, 5
	if cacheSize == 0:
		answer = len(cities) * cache_miss
	else :
		for city in cities:
			# cache가 cacheSize보다 작은 경우
			if (len(cache) < cacheSize):
				if (cache.count(city) == 1) :
					cache.remove(city)
					cache.append(city)
					answer += cache_hit
				else :
					cache.append(city)
					answer += cache_miss
			# 가득 찬 경우
			else :
				# 있는 경우 지우고, 뒤에 삽입
				if (cache.count(city) == 1) :
					cache.remove(city)
					cache.append(city)
					answer += cache_hit
				# cache안에 없는 경우 -> 앞에 있는 것 지우고, 삽입
				else :
					cache.pop(0)
					cache.append(city)
					answer += cache_miss
	return answer
'''
	참고자료
	파이썬 리스트
	https://wikidocs.net/14
	파이썬 대소문자
	https://hogni.tistory.com/119
'''