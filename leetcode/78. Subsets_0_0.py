"""
    부분 집합
    https://leetcode.com/problems/subsets/

    모든 부분 집합을 리턴하라
"""
from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []

        def dfs(index, elements):
            result.append(elements[:])

            if index > len(nums):
                return

            for i in range(index, len(nums)):
                elements.append(nums[i])
                dfs(i + 1, elements)
                elements.pop()

        dfs(0, [])

        return result

a = Solution()
nums = [1,2,3]
print(a.subsets(nums))