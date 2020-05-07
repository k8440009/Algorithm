# 징검다리 건너기
# https://programmers.co.kr/learn/courses/30/lessons/64062

def possible(stones, limit, k):
    cnt = k
    for stone in stones:
        if stone < limit:
            if (cnt == 1):
                return False
            else:
                cnt -= 1
        else:
            cnt = k
    return True
    
def solution(stones, k):
    start, end = 0, 200000000
    while start + 1 < end:
        mid = (start + end) // 2
        if possible(stones, mid, k):
            start = mid
        else:
            end = mid
    #print(start)
    return start

#solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3)