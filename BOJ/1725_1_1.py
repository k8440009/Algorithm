'''
    히스토그램 (분할 정복)
    https://www.acmicpc.net/problem/1725
'''
from sys import stdin
input = stdin.readline


def histogram(left, right):
    if left == right:   # 기저 사례
        return h[left]
    mid = (left + right) // 2
    result = max(histogram(left, mid), histogram(mid + 1, right))

    low = mid
    high = mid + 1

    height = min(h[low], h[high])
    result = max(result, height * 2)    # 밑변이 2인 것의 높이

    while left < low or high < right:
        if high < right and (low == left or h[low-1] < h[high + 1]):
            high += 1
            height = min(height, h[high])
        else:
            low -= 1
            height = min(height, h[low])
        result = max(result, height * (high - low + 1))
    return result


N = int(input())
h = []


for _ in range(N):
    h.append(int(input()))

print(histogram(0, N-1))
