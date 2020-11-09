# 가운데 글자 가져오기
# https://programmers.co.kr/learn/courses/30/lessons/12903
def solution(s):
    answer = ''
    size = len(s)
    if (size % 2) :
        answer = s[size // 2]
    else:
        answer += (s[size // 2 - 1])
        answer += (s[size // 2])
    return answer