'''
    암호 만들기
    https://www.acmicpc.net/problem/1759
'''
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
L, C = map(int, input().split())
alpha = list(map(str, input().split()))
alpha.sort()
passwords = []


def dfs(pos, password):
    # 기저 1 : 암호 길이가 L
    if len(password) == L:
        if(check(password)):
            passwords.append(password)
        return
    # 기저 2 : pos이 주어진 알파벳 위치를 벗어나는 경우
    if pos == C:
        return
    dfs(pos + 1, password + alpha[pos])
    dfs(pos + 1, password)


def check(password):
    mo, ja = 0, 0
    for c in password:
        if c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u':
            mo += 1
        else:
            ja += 1
    if mo >= 1 and ja >= 2:
        return True
    return False


dfs(0, "")
for password in passwords:
    print(password)
