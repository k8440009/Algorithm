'''
    수빈이와 수열
    https://www.acmicpc.net/problem/10539
'''

N = int(input())
A = list(map(int, input().split()))
B = []
for i in range(N):
    B.append((i + 1) * A[i] - sum(B))
    print(B[i], end=' ')
# print(' '.join(list(map(str, B))))
