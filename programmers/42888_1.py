# 오픈 채팅방
# https://programmers.co.kr/learn/courses/30/lessons/42888
def solution(record):
	result = []
	user = dict()
	for data in record:
		lst = data.split(" ")
		cmd, uid = lst[0], lst[1]
		nickname = ""
		if cmd == "Enter" :
			nickname = lst[2]
		elif cmd == "Change":
			nickname = lst[2]
		elif cmd == "Leave":
			nickname = user[uid]
		user[uid] = nickname
	
	for data in record:
		lst = data.split(" ")
		cmd, uid = lst[0], lst[1]
		if cmd == "Enter":
			result.append(user[uid] + "님이 들어왔습니다.")
		elif cmd == "Leave":
			result.append(user[uid] + "님이 나갔습니다.")
	return result
# solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"])