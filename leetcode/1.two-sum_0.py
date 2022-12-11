"""
    1. 두수의 합
    https://leetcode.com/problems/two-sum/
"""
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_dict = {}
        for i, num in enumerate(nums):
            if target - num in num_dict:
                return [num_dict[target - num], i]
            num_dict[num] = i

a = Solution()
nums = [2, 7, 11, 15]
target = 9
print(a.twoSum(nums, target))