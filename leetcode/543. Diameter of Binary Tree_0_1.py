"""
    이진 트리의 직경
    https://leetcode.com/problems/diameter-of-binary-tree/

    DFS
"""
from typing import Optional


class Solution:
    longest: int = 0

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dfs(node: TreeNode) -> int:
            if not node:
                return -1

            # 왼족, 오른쪽의 각 리프 노드까지 탐색
            left = dfs(node.left)
            right = dfs(node.right)

            # 가장 긴 경로
            self.longest = max(self.longest, left + right + 2)
            # 상태 값
            return max(left, right) + 1

        dfs(root)
        return self.longest
