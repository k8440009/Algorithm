"""
    전체 수 n을 입력 받아 k의 조합을 리턴하여라

    n = 4, k = 2

    itertools 모듈
"""
import itertools
from typing import List
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return list(map(list, itertools.combinations(range(1, n + 1), k)))

a = Solution()
n, k = 4, 2
print(a.combine(n, k))