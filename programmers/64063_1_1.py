# 호텔 방 배정
# https://programmers.co.kr/learn/courses/30/lessons/64063
import sys
sys.setrecursionlimit(5000)
def find(room_number, rooms):
    if not room_number in rooms:
        rooms[room_number] = room_number + 1
    else:
        rooms[room_number] = find(rooms[room_number], rooms)
    return rooms[room_number]

def solution(k, room_number):
    answer = []
    rooms = dict()
    for num in room_number:
        empty_room = find(num, rooms) - 1
        answer.append(empty_room)
    # print(answer)
    return answer
# solution(10, [1,3,4,1,3,1])