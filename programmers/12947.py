# 하샤드 수
# https://programmers.co.kr/learn/courses/30/lessons/12947


def solution(x):
    answer = True
    a = 0
    b = x
    while x > 0:
        a += x % 10
        x //= 10

    if b % a != 0:
        answer = False
    return answer


solution(10)
