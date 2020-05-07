# 기타 레슨
# https://www.acmicpc.net/problem/2343
import sys
N,M = map(int, sys.stdin.readline().split())
lessen_size = list(map(int, sys.stdin.readline().split()))
start, end = 0, 0

def possible(film_size):
    total, limit = 0, M
    for time in lessen_size:
        if time > film_size:
            return False
        total += time
        if film_size < total:
            if limit == 1:
                return False
            limit -= 1
            total = time
    return True

for time in lessen_size:  
    end += time

while start + 1 < end:
    mid = (start + end) // 2
    if possible(mid):
        end = mid
    else:
        start = mid
print(end)