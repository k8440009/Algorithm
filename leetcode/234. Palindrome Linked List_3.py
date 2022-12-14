"""
    팰린드롬 연결 리스트
    https://leetcode.com/problems/palindrome-linked-list/

    3. 런너를 이용한 우아한 풀이
    - 런너 기법
    - 다중할당
"""
from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        rev = None
        slow = fast = head
        # 런너를 이용해 역순 연결리스트 구성
        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast:
            slow = slow.next
        # 팰린드롬 여부 확인
        while rev and rev.val == slow.val:
            slow, rev = slow.next, rev.next
        return not rev
"""
head 구조
ListNode{val: 1, next: ListNode{val: 2, next: ListNode{val: 2, next: ListNode{val: 1, next: None}}}}
"""