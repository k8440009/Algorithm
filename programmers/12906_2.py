# 같은 숫자는 싫어
# https://programmers.co.kr/learn/courses/30/lessons/12906
def solution(arr):
    answer = []
    for i in range(len(arr) - 1):
        if i == 0:
            answer.append(arr[i])
        if arr[i] != arr[i + 1]:
            answer.append(arr[i + 1])
    return answer