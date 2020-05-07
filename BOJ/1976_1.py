# 여행 가자
# https://www.acmicpc.net/problem/1976
import sys
N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
parent = [i for i in range(1000 + 2)]
board = [[0 for _ in range(200 + 2)] for _ in range(200 + 2)]
plan = []
def find(n):
    if n == parent[n]:
        return n
    parent[n] = find(parent[n])
    return parent[n]

def merge(a, b):
    a, b = find(a), find(b)
    if a == b:
        return
    parent[a] = b

for r in range(1, N + 1):
    tmp = sys.stdin.readline().split()
    for c in range(1, N + 1):
        board[r][c] = int(tmp[c - 1])
        if board[r][c] == 1:
            if find(r) != find(c):
                merge(r,c)
plan = list(map(int, sys.stdin.readline().split()))

flag = 1
root = find(plan[0])
for city in plan:
    if root != find(parent[city]):
        flag = 0
        break
if flag == 1:
    print("YES")
else:
    print("NO")
