"""
    278. First Bad Version
    https://leetcode.com/problems/first-bad-version/description/
    https://www.youtube.com/watch?v=qr9q11J0ytg&list=PLdHw4xVmS1ptYBtUBN7Z0lkiIDxu1SYWn

    이진 탐색
"""
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right = 1, n

        while left < right:
            mid = left + ((right - left) // 2) # overflow 방지

            if isBadVersion(mid):
                right = mid
            else:
                left = mid + 1
        return left
