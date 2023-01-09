"""
    1. 두수의 합
    https://leetcode.com/problems/two-sum/
"""
from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_dict = {}
        for i, num in enumerate(nums):
            if target - num in nums_dict:
                return [nums_dict[target - num], i]
            nums_dict[num] = i
a = Solution()
nums = [2,7,11,15]
target = 9
print(a.twoSum(nums, target))
