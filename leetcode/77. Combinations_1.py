"""
    전체 수 n을 입력 받아 k의 조합을 리턴하여라

    n = 4, k = 2

    dfs
"""
from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []

        def dfs(elements : List, start : int, k: int):
            if k == 0:
                result.append(elements[:])
                return

            # 자신 이전의 모든 값을 고정하여 재귀 호출
            for i in range(start, n + 1):
                elements.append(i)
                dfs(elements, i + 1, k - 1)
                elements.pop()

        dfs([], 1, k)
        return result