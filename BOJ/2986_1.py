'''
    파스칼
    https://www.acmicpc.net/problem/2986
'''
N = int(input())
i = 2
cnt = 1
while i*i <= N:
    if N % i == 0:
        cnt = N//i
        break
    i += 1
print(N-cnt)
