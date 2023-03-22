"""
    조합의 합
    https://leetcode.com/problems/combination-sum/

    중복 조합
"""
from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def dfs(sum, index, path):
            if sum < 0:
                return
            elif sum == 0:
                result.append(path)
                return

            for i in range(index, len(candidates)):
                dfs(sum - candidates[i], i, path + [candidates[i]])

        dfs(target, 0, [])

        return result
