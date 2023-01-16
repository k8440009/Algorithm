"""
    조합의 합
    숫자 집합 candidates를 조합하여 합이 target이 되는 원소를 나열하여라
"""

from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def dfs(csum, index, path):
            if csum < 0:
                return
            if csum == 0:
                result.append(path)

            # 자기 자신부터 하위 원소까지의 나열 재귀 호출
            for i in range(index, len(candidates)):
                dfs(csum - candidates[i], i, path + [candidates[i]])

        dfs(target, 0, [])

        return result