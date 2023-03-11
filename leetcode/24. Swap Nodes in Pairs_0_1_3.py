"""
    페어의 노드 스왑
    https://leetcode.com/problems/swap-nodes-in-pairs/description/

    1. 값만 교환
"""

# Definition for singly-linked list.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        root, prev = ListNode(None)
        prev.next = head

        while head or head.next:
            # b가 a(head)를 가리키도록 할당
            b = head.next