'''
    막대기 
    https://www.acmicpc.net/problem/17608 
'''
import sys
N = int(sys.stdin.readline())
myList = []
for _ in range(N):
    myList.append(int(sys.stdin.readline()))
myList.reverse()

height = 0
cnt = 0
for num in myList:
    if num > height:
        cnt += 1
        height = num
print(cnt)