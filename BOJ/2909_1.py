'''
    캔디 구매
    https://www.acmicpc.net/problem/2909
'''
C, K = map(int, input().split())
N = (10 ** K)
a = (C // N) * N
if (C % N >= (N // 2)):
    print(a + N)
else:
    print(a)
