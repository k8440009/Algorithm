"""
    계단 오르기
    https://leetcode.com/problems/climbing-stairs/

    재귀 구조 브루트 포스
"""


class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2

        return self.climbStairs(n - 1) + self.climbStairs(n - 2)
