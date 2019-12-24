'''
    문자열 판별
    https://www.acmicpc.net/problem/16500
'''
from sys import stdin
input = stdin.readline
MAX = 100 + 1
S = input().strip()
A = []
cache = [-1] * MAX

# dp로 문자열 위치들이 될 수 있는지 없는지 검사


def search(pos):
    # 기저 : 전에 검색 완료한 경우
    if(cache[pos] != -1):
        return cache[pos]
    # pos이 S의 길이와 같은 경우
    if(pos == len(S)):
        cache[pos] = 1
        return cache[pos]
    cache[pos] = 0
    for s in A:
        M = S[pos:pos + len(s)]
        if M == s:
            cache[pos] |= search(pos + len(s))
    return cache[pos]


for _ in range(int(input())):
    A.append(input().strip())

print(search(0))
