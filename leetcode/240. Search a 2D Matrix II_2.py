"""
    2D 행렬 검색 2
    https://leetcode.com/problems/search-a-2d-matrix-ii/

    파이썬 다운 방식
"""
from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        return any(target in row for row in matrix)