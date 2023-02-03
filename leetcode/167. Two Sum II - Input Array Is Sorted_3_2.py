"""
    두 수의 합 2
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

    biset 모듈 + 슬라이싱 최소화
"""
import bisect
from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for k, v in enumerate(numbers):
            expected = target - v
            nums = numbers[k + 1:]
            i = bisect.bisect_left(nums, expected)
            if i < len(nums) and numbers[i + k + 1] == expected:
                return k + 1, i + k + 2
