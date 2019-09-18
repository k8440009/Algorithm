# 최대 공약수와 최소 공배수
# https://programmers.co.kr/learn/courses/30/lessons/12940


def GCD(a, b):
    return GCD(b, a % b) if b else a


def LCM(a, b):
    if a == 0 or b == 0:
        return a + b
    return a / GCD(a, b) * b


def solution(n, m):
    answer = []
    answer.append(GCD(n, m))
    answer.append(LCM(n, m))
    return answer
