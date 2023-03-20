"""
    섬의 개수
    https://leetcode.com/problems/number-of-islands/

    dfs
"""
from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        def dfs(r:int, c:int):
            if r < 0 or r >= len(grid) \
                    or c < 0 or c >= len(grid[0]) \
                    or grid[r][c] != "1":
                return
            grid[r][c] = 0

            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

        count = 0
        for r in range(grid):
            for c in range(grid[0]):
                if grid[r][c] == "1":
                    dfs(r, c)
                    count += 1

        return count
