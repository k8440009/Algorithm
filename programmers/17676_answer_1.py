# 추석 트래픽
# https://programmers.co.kr/learn/courses/30/lessons/17676

def time2durationSec(time):
	lst = time.split(' ')
	end = lst[1]
	duration = lst[2]
	# print(end, duration)
	lst2 = end.split(":")
	hour = int(lst2[0])*1000
	minu = int(lst2[1])*1000
	sec = int(lst2[2][0:2] + lst2[2][3:])
	micsec = hour*3600 + minu*60 + sec
	lst3 = duration[:-1].split('.')
	# print(lst3)
	if len(lst3) > 1:
		duration2 = int(lst3[0]) * 1000 + int(lst3[1] + ('0' * (3 - len(lst3[1]))))
		# print(duration2)
	else :
		duration2 = int(lst3[0]) * 1000
	return [micsec - duration2 + 1, micsec] # 시작시간, 끝 시간

def checkProcessNum(time, lst):
	num = 0
	start = time
	end = time + 1000
	print(lst)
	for duration in lst :
		if not (duration[1] < start or duration[0] >= end):
			num += 1
	return num
def solution(lines):
	lst = []
	count = []
	for str in lines:
		lst.append(time2durationSec(str))
	print(lst)
	for i in lst:
		count.append(checkProcessNum(i[0], lst))
		count.append(checkProcessNum(i[1], lst))
	return max(count)

#solution(["2016-09-15 00:00:00.000 3s"])
# solution(["2016-09-15 23:59:59.999 0.001s"])
# solution(["2016-09-15 23:59:59.999 0.121s"])
# solution(["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"])
# solution(["2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"])
# solution(["2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"])
# solution(["2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"])

# 참고자료
# https://geonlee.tistory.com/42
# https://inspirit941.tistory.com/entry/Python-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-2018-%EC%B9%B4%EC%B9%B4%EC%98%A4-Recruit-%EC%B6%94%EC%84%9D-%ED%8A%B8%EB%9E%98%ED%94%BD