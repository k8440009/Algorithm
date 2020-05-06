# 징검다리 건너기 (효율성 x)
# https://programmers.co.kr/learn/courses/30/lessons/64062
def solution(stones, k):
    kid = 0
    cnt = 0
    while (cnt != k):
        for index in range(len(stones)):
            if stones[index] > 0:
                stones[index] -=1
                cnt = 0
            elif stones[index] == 0:
                cnt += 1
            if (cnt == k):
                break
        if(cnt != k):
            kid += 1
            cnt = 0
        #print(kid,end=" ")
        #print(stones)
    return kid

#solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3)