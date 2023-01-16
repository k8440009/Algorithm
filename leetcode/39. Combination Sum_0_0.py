"""
    조합의 합
    숫자 집합 candidates를 조합하여 합이 target이 되는 원소를 나열하여라

    내 풀이
"""

from typing import List
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def dfs(elements, start, sum):
            if sum >= target:
                if sum == target:
                    result.append(elements[:])

                return

            for i in range(start, len(candidates)):
                elements.append(candidates[i])
                dfs(elements, i, sum + candidates[i])
                elements.pop()

        dfs([], 0, 0)

        return result

a = Solution()
candidates, target = [2,3,6,7], 7
# Output: [[2,2,3],[7]]
print(a.combinationSum(candidates, target))