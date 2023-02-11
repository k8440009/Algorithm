"""
    피보나치 수
    https://leetcode.com/problems/fibonacci-number/

    메모이제이션
"""
import collections


class Solution:
    dp = collections.defaultdict(int)

    def fib(self, n: int) -> int:
        if n <= 1:
            return n

        if self.dp[n]:
            return self.dp[n]

        self.dp[n] = self.fib(n - 1) + self.fib(n - 2)

        return self.dp[n]
