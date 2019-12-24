'''
    가장 긴 증가하는 부분 수열 O(N^2), DP
    https://www.acmicpc.net/problem/11053 
'''
from sys import stdin
input = stdin.readline
MAX = 1000 + 1
N = int(input())
S = list(map(int, input().split()))
cache = []

# cache[start] : start에서 시작한 수열의 길이


def LIS(start):
    # 전에 계산된 경우
    if cache[start] != -1:
        return cache[start]
    cache[start] = 1
    for next in range(start + 1, N):
        if(S[start] < S[next]):
            cache[start] = max(cache[start], LIS(next) + 1)
    return cache[start]


def init():
    global cache
    cache = [-1] * MAX


init()
answer = 0
for i in range(N):
    answer = max(answer, LIS(i))
print(answer)
