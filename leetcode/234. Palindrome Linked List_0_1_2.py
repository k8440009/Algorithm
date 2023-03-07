"""
    팰린드롬 연결 리스트
    https://leetcode.com/problems/palindrome-linked-list/

    2. 러너 기법
"""
import collections
from typing import Optional, Deque


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        rev = None
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next

        # 홀수일 때는 slow 런너가 한 칸 더 앞으로 이동하여 중앙의 값을 빗겨 나가야한다.
        if fast:
            slow = slow.next

        # 팰린드롬 여부 확인
        while rev and rev.val == slow.val:
            slow, rev = slow.next, rev.next

        return not rev
