'''
    유레카 이론
    https://www.acmicpc.net/problem/10448
'''
from sys import stdin


def ureka(num):
    for i in range(len(T)):
        for j in range(len(T)):
            for k in range(len(T)):
                if num == T[i] + T[j] + T[k]:
                    return True
    return False


TC = int(stdin.readline())
n = 1
T = []
while (n) * (n+1) / 2 < 1000:
    num = (n) * (n+1) / 2
    T.append(num)
    n += 1
for ts in range(TC):
    N = int(stdin.readline())
    print(1 if ureka(N) else 0)
