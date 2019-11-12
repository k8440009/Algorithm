'''
    타임 카드
    https://www.acmicpc.net/problem/5575
'''
for _ in range(3):
    time = list(map(int, input().split()))
    startWork = 3600 * time[0] + 60 * time[1] + time[2]
    endWork = 3600 * time[3] + 60 * time[4] + time[5]
    working = endWork - startWork
    print(working//3600, working % 3600 // 60, working % 3600 % 60)
