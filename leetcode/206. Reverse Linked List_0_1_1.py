"""
    역순 연결 리스트
    1. 재귀 뒤집기
"""
from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(node : ListNode, prev: ListNode = None):
            if not node:
                return prev

            next, node.next = node.next, prev

            return reverse(next, node)

        return reverse(head)