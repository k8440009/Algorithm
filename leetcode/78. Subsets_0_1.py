"""
    부분 집합
    모든 부분 집합을 리턴하라
"""
from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []

        def dfs(index, path):
            result.append(path)

            if index > len(nums):
                return

            for i in range(index, len(nums)):
                dfs(i + 1, path + [nums[i]])

        dfs(0, [])

        return result

a = Solution()
nums = [1,2,3]
print(a.subsets(nums))