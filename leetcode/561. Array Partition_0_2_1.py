"""
    배열 파티션 1
    https://leetcode.com/problems/array-partition/

    정렬 후 리스트 컴프리핸션으로 짝수 처리
"""
from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])

a = Solution()
nums = [6,2,6,5,1,2]
print(a.arrayPairSum(nums))