"""
    2D 행렬 검색 2
    https://leetcode.com/problems/search-a-2d-matrix-ii/

    첫 행의 맨 뒤에서 탐색
"""
from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # 예외 처리
        if not matrix:
            return False

        # 첫 행의 맨 뒤
        row = 0
        col = len(matrix[0]) - 1

        while row <= len(matrix) - 1 and col >= 0:
            if target == matrix[row][col]:
                return True
            elif target < matrix[row][col]:  # 타겟이 작으면 왼쪽으로 이동
                col -= 1
            elif target > matrix[row][col]:  # 타겟이 크면 아래쪽으로 이동
                row += 1

        return False
