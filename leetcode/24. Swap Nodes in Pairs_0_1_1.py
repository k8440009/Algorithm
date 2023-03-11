"""
    페어의 노드 스왑
    https://leetcode.com/problems/swap-nodes-in-pairs/description/

    1. 값만 교환
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head

        while cur and cur.next:
            cur.val, cur.next.val = cur.next.val, cur.val
            cur = cur.next.next

        return head