'''
    숫자 야구
    https://www.acmicpc.net/problem/2503
'''
from sys import stdin


def init():
    for i in range(123, MAX):
        now = str(i)
        if now[0] == now[1] or now[1] == now[2] or now[2] == now[0]:
            continue
        elif now[0] == "0" or now[1] == "0" or now[2] == "0":
            continue
        check[i] = True


MAX = 1000
check = [False for i in range(MAX)]

init()

questionCnt = int(stdin.readline())
for _ in range(questionCnt):
    quesion = list(map(str, stdin.readline().strip().split()))
    point = quesion[0]
    strike = int(quesion[1])
    ball = int(quesion[2])
    for i in range(123, MAX):
        now = str(i)
        strikeCnt = 0
        ballCnt = 0
        for y in range(3):
            for x in range(3):
                if y == x and now[y] == point[x]:
                    strikeCnt += 1
                if y != x and now[y] == point[x]:
                    ballCnt += 1
        if strike != strikeCnt or ball != ballCnt:
            check[i] = False
print(check.count(True))
