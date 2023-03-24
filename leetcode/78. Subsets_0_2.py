"""
    부분 집합
    https://leetcode.com/problems/subsets/

    모든 부분 집합을 리턴하라
"""
from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []

        def dfs(index, path):
            result.append(path)

            for i in range(index, len(nums)):
                dfs(i + 1, path + [nums[i]])

        dfs(0, [])

        return result
