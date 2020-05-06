# 호텔 방 배정 (효율성 x)
# https://programmers.co.kr/learn/courses/30/lessons/64063
def solution(k, room_number):
    answer = []
    room = dict()
    for room_key in room_number:
        key = room_key
        while(key in room):
            key += 1
        room[key] = 1
        answer.append(key)
    #print(answer)
    return answer

solution(10, [1,3,4,1,3,1])