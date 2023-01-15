"""
    이진트리의 반전
    - 반복 구조로 DFS 후위 순회
"""
import collections
from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        stack = collections.deque([root])

        while stack:
            node = stack.pop()
            # 부모 노드부터 하양식 스왑
            if node:
                stack.append(node.left)
                stack.append(node.right)

                node.left, node.right = node.right, node.left

        return root
