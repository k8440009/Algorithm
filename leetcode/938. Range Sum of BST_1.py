"""
    이진 탐색 트리(BST) 합의 범위
    재귀 구조 DFS로 브루트 포스
"""
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if not root:
            return 0

        return (root.val if low <= root.val <= high else 0) + \
               self.rangeSumBST(root.left, low, high) + \
               self.rangeSumBST(root.right, low, high)
