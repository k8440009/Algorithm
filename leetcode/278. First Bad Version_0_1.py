"""
    278. First Bad Version
    https://leetcode.com/problems/first-bad-version/description/

    이진 탐색
    - 처음 에러 버전 이후로 모든 버전은 문제이니 문제 버전의 최소값을 찾으면된다.
    - 1 <= bad <= n <= 2^31 - 1 데이터의 크기가 매우 크니 O(nlogN) 방식인 이진 검색을 사용하여 최소값을 찾는다.
"""
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right = 1, n

        while left <= right:
            mid = (left + right) // 2

            if isBadVersion(mid) is False:
                left = mid + 1
            elif isBadVersion(mid) is True:
                right = mid - 1

        return left
