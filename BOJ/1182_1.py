'''
    부분수열의 합
    https://www.acmicpc.net/problem/1182
'''
from sys import stdin

answer = 0


def rec(index, total):

    if index == N:
        if total == S:
            global answer
            answer += 1
        return
    rec(index + 1, total + nums[index])
    rec(index + 1, total)


N, S = map(int, stdin.readline().split())
nums = list(map(int, stdin.readline().split()))
if(S == 0):
    answer -= 1
rec(0, 0)
print(answer)
