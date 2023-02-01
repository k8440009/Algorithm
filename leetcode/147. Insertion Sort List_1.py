"""
    삽입 정렬 리스트
    https://leetcode.com/problems/insertion-sort-list/

    삽입 정렬
"""
from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = parent = ListNode(None)

        while head:
            while cur.next and cur.next.val < head.val:
                cur = cur.next

            cur.next, head.next, head, = head, cur.next, head.next

            cur = parent

        return cur.next