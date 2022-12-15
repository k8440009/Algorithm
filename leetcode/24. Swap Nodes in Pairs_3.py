"""
    페어의 노드 스왑
    3. 재귀 구조로 스왑
"""
from typing import Optional
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head and head.next:
            p = head.next
            # 스왑된 값 리턴 값음
            head.next = self.swapPairs(p.next)
            p.next = head
            return p
        return head
