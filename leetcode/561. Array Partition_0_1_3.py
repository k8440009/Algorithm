"""
    배열 파티션 1
    - 파이썬 방식
"""
from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])
