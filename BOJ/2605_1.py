'''
    줄 세우기
    https://www.acmicpc.net/problem/2605
'''
import sys
input = sys.stdin.readline
N = int(input())
pick = list(map(int, input().split()))
location = []
for i in range(N):
    location.insert(pick[i], i + 1)
location.reverse()
for i in range(N):
    print(location[i], end=" ")
