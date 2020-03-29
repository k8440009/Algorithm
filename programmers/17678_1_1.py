# 셔틀 버스
# https://programmers.co.kr/learn/courses/30/lessons/17678

def timeToMinute (time):
	lst = time.split(':')
	return int(lst[0]) * 60 + int(lst[1])

def minuteToTime(minute):
	div, mod = divmod(minute, 60)
	# 지정자를 사용하여 시간으로 변환
	return "%02d:%02d" % (div, mod)

def crewTime(timetable) :
	return [timeToMinute(time) for time in timetable]

def shuttleTime(n, t):
	shuttle = [timeToMinute("09:00")]
	for _ in range(n - 1):
		shuttle.append(shuttle[-1] + t)
	return shuttle
		
def solution(n, t, m, timetable):
	answer = ''
	crew = sorted(crewTime(timetable))
	shuttle = shuttleTime(n,t)

	waiting = []
	for i in range(n - 1):
		busTime = shuttle[i]
		cnt = 0
		for time in crew:
			if time <= busTime and cnt < m:
				waiting.append(time)
				cnt += 1
		for _ in range(cnt):
			crew.pop(0)
			waiting.pop(0)
	cnt = 0
	busTime = shuttle[-1]
	for time in crew:
		if time <= busTime and cnt < m:
			waiting.append(time)
			cnt += 1
	if len(waiting) >= m:
		answer = waiting[-1] - 1
	else:
		answer = busTime
	answer = minuteToTime(answer)
	return answer

'''
solution(1, 1, 5, ["08:00", "08:01", "08:02", "08:03"])
solution(2,10,2, ["09:10", "09:09", "08:00"])
solution(2,1,2, ["09:00", "09:00", "09:00", "09:00"])
solution(1,1,5, ["00:01", "00:01", "00:01", "00:01", "00:01"])
solution(1,1,1, ["23:59"])
solution(10, 60, 45, ["23:59","23:59", "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59","23:59", "23:59", "23:59"])
'''