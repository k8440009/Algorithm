"""
    주식을 사고팔기 가장 좋은 시점 2
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

    파이썬 다운 방식
"""
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 0보다 크면 무조건 합산
        return sum(max(prices[i + 1] - prices[i], 0) for i in range(len(prices) - 1))
