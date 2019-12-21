'''
    ls
    https://www.acmicpc.net/problem/5015
'''
from sys import stdin
input = stdin.readline

MAX = 100 + 1
W = input().strip()  # 패턴
S = ""  # 문자열
N = int(input())
'''
    -1: 아직 답이 계산되지 않음
    0 : 해당 입력들이 서로 대응되지 않음
    1 : 해당 입력들이 서로 대응됨
'''
cache = [[-1] * MAX for _ in range(MAX)]


def MatchMemoized(w, s):
    # 메모이제이션
    if cache[w][s] != -1:
        return cache[w][s]
    # 더 이상 대응되지 않을 때 까지
    while s < len(S) and w < len(W) and W[w] == S[s]:
        cache[w][s] = MatchMemoized(w + 1, s + 1)
        return cache[w][s]
    # 패턴 끝에 도달해서 끝난 경우
    if w == len(W):
        cache[w][s] = (1 if s == len(S) else 0)
        return cache[w][s]
    # *를 만나서 끝난 경우
    if W[w] == '*':
        if MatchMemoized(w + 1, s) or (s < len(S) and MatchMemoized(w, s + 1)):
            cache[w][s] = 1
            return cache[w][s]

    cache[w][s] = 0
    return cache[w][s]


def init():
    global cache
    cache = [[-1] * MAX for _ in range(MAX)]


answers = []
for _ in range(N):
    S = input().strip()
    init()
    if MatchMemoized(0, 0):
        answers.append(S)

for answer in answers:
    print(answer)
