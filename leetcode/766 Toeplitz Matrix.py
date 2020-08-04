class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        for y in reversed(range(len(matrix))):
            for cnt in range(len(matrix)):
                matrix[len(matrix) - cnt][0]