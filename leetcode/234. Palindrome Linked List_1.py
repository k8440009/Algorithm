"""
    팰린드롬 연결 리스트
    https://leetcode.com/problems/palindrome-linked-list/

    1. 리스트 변환
"""
from typing import Optional, List


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        q: List = []

        # if not head:
        #     return True

        node = head
        # 리스트 변환
        while node is not None:
            q.append(node.val)
            node = node.next

        # 팰린 드롬 판별
        while len(q) > 1:
            if q.pop(0) != q.pop():
                return False

        return True
"""
head 구조
ListNode{val: 1, next: ListNode{val: 2, next: ListNode{val: 2, next: ListNode{val: 1, next: None}}}}
"""