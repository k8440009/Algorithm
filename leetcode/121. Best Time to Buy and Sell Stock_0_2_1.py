"""
    주식을 사고팔기 가장 좋은 시점
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    저점과 현재 값과의 차이 계산
"""
import sys
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_cost = -sys.maxsize
        min_cost = sys.maxsize
        for price in prices:
            min_cost = min(price, min_cost)
            max_cost = max(price - min_cost, max_cost)

        return max_cost


a = Solution()
# prices = [7,1,5,3,6,4]
prices = [7, 6, 4, 3, 1]
print(a.maxProfit(prices))
