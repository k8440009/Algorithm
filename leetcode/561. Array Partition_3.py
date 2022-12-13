"""
    배열 파티션 1
    3. 파이썬 방식
"""
from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])

a = Solution()
nums = [1,4,3,2]
print(a.arrayPairSum(nums))