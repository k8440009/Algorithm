# 최댓값과 최솟값
# https://programmers.co.kr/learn/courses/30/lessons/12939


def solution(s):
    answer = ''
    s = list(map(int, s.split()))
    answer += str(min(s)) + " " + str(max(s))
    return answer
