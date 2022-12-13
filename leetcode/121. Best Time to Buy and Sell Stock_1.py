"""
    주식을 사고팔기 가장 좋은 시점
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    1. 브루트 포스
    : timeout
"""
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_price = 0
        for i, price in enumerate(prices):
            for j in range(i, len(prices)):
                max_price = max(prices[j] - price, max_price)
        return max_price

a = Solution()
prices = [7,1,5,3,6,4]
print(a.maxProfit(prices))