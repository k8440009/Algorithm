# K 번째 수
# https://programmers.co.kr/learn/courses/30/lessons/42748
def solution(array, commands):
    answer = []
    for _ in range(0, len(commands)):
        st, ed, pos = commands
        new_arr = array[st- 1:ed]
        new_arr.sort()
        answer.append(new_arr[pos-1])
    return answer
