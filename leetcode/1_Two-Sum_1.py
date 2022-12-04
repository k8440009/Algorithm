"""
    1. 두수의 합
    - 브루트 포스를 사용하여 처리
    https://leetcode.com/problems/two-sum/
"""
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]



a = Solution()
nums = [2,7,11,15]
target = 9
print(a.twoSum(nums, target))