"""
    피보나치 수
    https://leetcode.com/problems/fibonacci-number/

    타뷸레이션
    - 상향식 풀이
"""
import collections


class Solution:
    dp = collections.defaultdict(int)

    def fib(self, n: int) -> int:
        self.dp[0] = 0
        self.dp[1] = 1

        for i in range(2, n + 1):
            self.dp[i] = self.dp[i - 1] + self.dp[i - 2]

        return self.dp[n]
