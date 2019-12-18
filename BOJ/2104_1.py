'''
    부분배열 고르기
    https://www.acmicpc.net/problem/2104
'''
from sys import stdin
input = stdin.readline


def divideAndConquer(left, right):
    if(left == right):
        return scores[left] * scores[left]
    mid = (left + right) // 2
    result = max(divideAndConquer(left, mid),
                 divideAndConquer(mid + 1, right))
    low = mid
    high = mid + 1
    total = scores[low] + scores[high]
    minValue = min(scores[low], scores[high])
    result = max(result, minValue * total)
    while left < low or high < right:
        if high < right and (low == left or scores[low-1] < scores[high+1]):
            high += 1
            total += scores[high]
            minValue = min(minValue, scores[high])
        else:
            low -= 1
            total += scores[low]
            minValue = min(minValue, scores[low])
        result = max(result, minValue * total)
    return result


N = int(input())
scores = list(map(int, input().split()))
print(divideAndConquer(0, N-1))
