'''
    폭죽쇼
    https://www.acmicpc.net/problem/1773
'''
N, C = map(int, input().split())
check = [0] * (C+1)
answer = 0
for _ in range(N):
    bomb = int(input())
    if check[bomb] == True:
        continue
    for i in range(bomb, C+1, bomb):
        if not check[i]:
            check[i] = True
            answer += 1
print(answer)
