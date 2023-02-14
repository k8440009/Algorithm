"""
    최대 서브 배열
    https://leetcode.com/problems/maximum-subarray/

    카데인 알고리즘
"""
import sys
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best_sum = -sys.maxsize
        current_sum = 0

        for num in nums:
            current_sum = max(num, current_sum + num)
            best_sum = max(best_sum, current_sum)

        return best_sum
