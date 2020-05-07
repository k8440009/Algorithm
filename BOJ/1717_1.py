# 집합의 표현
# https://www.acmicpc.net/problem/1717

import sys
N,M = map(int, sys.stdin.readline().split()) 
parent = [i for i in range(N + 1)]

def find(n):
    if n == parent[n]:
        return n
    parent[n] = find(parent[n])
    return parent[n]

def merge(a, b):
    a, b = find(a), find(b)
    if a == b:
        return
    else:
        parent[a] = b

for _ in range(M):
    op,a,b = map(int, sys.stdin.readline().split())
    if op == 0:
        merge(a,b)
    elif op == 1:
        a, b = find(a), find(b)
        if a == b:
            print("YES")
        else:
            print("NO")