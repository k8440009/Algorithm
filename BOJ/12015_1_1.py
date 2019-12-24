
'''
    가장 긴 증가하는 부분 수열 2 O(NlogN), 이분탐색
    https://www.acmicpc.net/problem/11053 
'''
from sys import stdin
from bisect import bisect_left
input = stdin.readline
INF = 987654321
N = int(input())
S = list(map(int, input().split()))
sub = []
sub.append(INF)

for num in S:
    # 리스트 마지막 값 보다 숫자가 큰 경우
    if num > sub[-1]:
        sub.append(num)
    # 리스트 마지막 값 보다 숫자가 작은 경우 => 이분탐색하여 num보다 작은 위치 찾음
    else:
        sub[bisect_left(sub, num, 0, len(sub))] = num

print(len(sub))

'''
    참고
    https://docs.python.org/ko/dev/library/bisect.html
'''
