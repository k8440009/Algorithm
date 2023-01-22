"""
    정렬된 배열의 이진 탐색 트리 변환
    - 이진 검색 결과로 트리 구성
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
"""
from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None

        mid = len(nums) // 2

        # 분할 정복으로 이진 검색 결과 트리 구성
        node = TreeNode(nums[mid])
        node.left = self.sortedArrayToBST(nums[:mid])
        node.right = self.sortedArrayToBST(nums[mid + 1:])

        return node
