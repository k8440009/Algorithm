"""
    1. 두수의 합
    - 타겟에서 num 을 뺀다.
    - 그 후 해당 인덱스 다음 부테 데이터를 추출하고, 데이터를 추출한 것의 인덱스는 다르므로, 보정해준다.
    https://leetcode.com/problems/two-sum/
"""
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i, n in enumerate(nums):
            complement = target - n
            if complement in nums[i + 1:]:
                return [nums.index(n), nums[i + 1:].index(complement) + (i + 1)]

a = Solution()
nums = [2,7,11,15]
target = 9
print(a.twoSum(nums, target))