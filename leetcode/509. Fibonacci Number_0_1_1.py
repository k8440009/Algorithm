"""
    피보나치 수
    https://leetcode.com/problems/fibonacci-number/

    메모이제이션
"""
import collections


class Solution:
    dp = collections.defaultdict(int)
    def fib(self, N: int) -> int:
        if N <= 1:
            return N

        if self.dp[N]:
            return self.dp[N]

        self.dp[N] = self.fib(N - 1) + self.fib(N - 2)
        return self.dp[N]
