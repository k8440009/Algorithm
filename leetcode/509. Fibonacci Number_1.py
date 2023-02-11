"""
    피보나치 수
    https://leetcode.com/problems/fibonacci-number/

    재귀 구조 브루트 포스
"""
class Solution:
    def fib(self, n: int) -> int:
        if n <= 1:
            return n

        return self.fib(n - 1) + self.fib(n - 2)

