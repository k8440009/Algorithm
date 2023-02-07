"""
    주식을 사고팔기 가장 좋은 시점 2
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

    그리디 알고리즘
    - 내리기전에 팔고, 오르기전에 사면 된다.
"""
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        result = 0
        # 값이 오르는 경우 매번 그리디 계산
        for i in range(len(prices) - 1):
            if prices[i + 1] > prices[i]:
                result += prices[i + 1] - prices[i]

        return result
