"""
    피보나치 수
    https://leetcode.com/problems/fibonacci-number/

    두 변수만 이용해 공간 절약
"""
class Solution:
    def fib(self, n: int) -> int:
        x, y = 0, 1
        for i in range(0, n):
            x, y = y, x + y
        return x
