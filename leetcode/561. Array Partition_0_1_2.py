"""
    배열 파티션 1
    - 짝수번째 값 계산
"""
from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        sum = 0
        nums.sort()

        for i, n in enumerate(nums):
            # 짝수 번째 값 계산
            if i % 2 == 0:
                sum += n
        return sum
