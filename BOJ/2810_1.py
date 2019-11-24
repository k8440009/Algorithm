'''
    컵홀더
    https://www.acmicpc.net/problem/2810
'''
N = int(input())
SEAT = input()
flag = 0
cnt = 1
for i in range(len(SEAT)):
    if(SEAT[i] == 'S'):
        cnt += 1
    else:
        flag += 1
        if(flag == 2):
            cnt += 1
            flag = 0
print(min(cnt, N))
