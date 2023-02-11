"""
    과반수 엘리먼트
    https://leetcode.com/problems/majority-element/

    분할정복
    - 병합 정렬
"""
import collections
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if not nums:
            return None
        if len(nums) == 1:
            return nums[0]

        half = len(nums) // 2
        a = self.majorityElement(nums[:half])
        b = self.majorityElement(nums[half:])

        return [b, a][nums.count(a) > half]
