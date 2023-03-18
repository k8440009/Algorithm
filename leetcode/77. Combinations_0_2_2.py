"""
    조합
    https://leetcode.com/problems/combinations/

    itertools
"""
import itertools
from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return map(list, itertools.combinations(range(1, n + 1), k))
