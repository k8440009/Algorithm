"""
    322. Coin Change
    https://leetcode.com/problems/coin-change/
    다이나믹

    https://medium.com/codex/leetcode-322-coin-change-python-solution-3ee10793cd6b
"""
from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0

        for a in range(1, amount + 1):
            for c in coins:
                if a - c >= 0:
                    dp[a] = min(dp[a], 1 + dp[a - c])

        return dp[amount] if dp[amount] != amount + 1 else -1
