"""
    주식을 사고팔기 가장 좋은 시점
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    2. 저점과 현재 값과의 차이 계산
"""
import sys
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        min_price = sys.maxsize

        # 최솟값가 최댓값 계속 생신
        for price in prices:
            min_price = min(min_price, price)
            profit = max(profit, price - min_price)
        return profit

a = Solution()
prices = [7,1,5,3,6,4]
print(a.maxProfit(prices))