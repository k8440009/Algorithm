# 셔틀 버스
# https://programmers.co.kr/learn/courses/30/lessons/17678

def timeToMinute (time):
	lst = time.split(':')
	return int(lst[0]) * 60 + int(lst[1])

def minuteToTime (minute):
	div, mod = divmod(minute, 60)
	return "%02d:%02d" % (div, mod)

def crewTime(timetable) :
	return [timeToMinute(time) for time in timetable]

def shuttleTime(n, t, start = "09:00"):
	shuttle = [timeToMinute(start)]
	for _ in range(n - 1):
		shuttle.append(shuttle[-1] + t)
	return shuttle

def duplicateTime(c, integreate) :
	if not c in integreate.keys():
		return c
	else : 
		return duplicateTime(c + 0.001, integreate)

def solution(n, t, m, timetable):
	answer = ''
	crew = sorted(crewTime(timetable))
	#print(crew)
	shuttle = shuttleTime(n,t)
	#print(shuttle)
	conTime = set(shuttle + crew) # 셔틀 시간 + 크루들의 시간의 집합
	# print(conTime)
	# 추가적으로 가능성 있는 시간으로 해당 시간에 1초를 뺀값을 집합에 추가하여 정답의 가능성을 가진 것들만 모인 conTime을 만든다.
	for c in set(crew):
		conTime.add(c-1)
	print(conTime)
	# 시간이 큰것 부터 내림차순으로 확인하게 되면 콘이 버스를 못타다가 처음으로 버스를 탈 수 있는 시간을 구할 수 있다.
	for con in sorted(list(conTime))[::-1]:
		integreate = dict()
		for c in crew :
			integreate[duplicateTime(c, integreate)] = 'crew'
		integreate[duplicateTime(con, integreate)] = 'con'
		for sh in shuttle:
			integreate[duplicateTime(sh, integreate)] = 'shuttle'
		waiting_line = []
		for time in sorted(integreate.keys()):
			if 'crew' == integreate[time]:
				waiting_line.append('crew')
			elif 'con' == integreate[time]:
				waiting_line.append('con')
			elif 'shuttle' == integreate[time]:
				waiting_line = waiting_line[m:]
		if not 'con' in waiting_line:
			return minuteToTime(con)

	return answer


solution(2,10,2, ["09:10", "09:09", "08:00"])

# 참고 자료
# https://geonlee.tistory.com/39