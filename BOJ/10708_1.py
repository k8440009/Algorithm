'''
    크리스마스 파티
    https://www.acmicpc.net/problem/10708
'''
N = int(input())
M = int(input())
target = list(map(int, input().split()))
score = [0] * (N)
# 게임 수 많큼 반복
for i, target_num in enumerate(target):
    cnt = 0
    game = list(map(int, input().split()))
    for j, check in enumerate(game):
        if check == target_num:
            score[j] += 1
        else:
            cnt += 1
    score[target_num-1] += cnt
for s in score:
    print(s)
