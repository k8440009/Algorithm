"""
    두 정렬 리스트의 병합
    1. 재귀 구조로 연결
    https://leetcode.com/problems/merge-two-sorted-lists/
    - 변수 스왑
"""
from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """
            재귀와 스왑을 사용하여 병합 리스트를 생성한다.
        """
        if (not list1) or (list2 and list1 > list2):
            list1, list2 = list2, list1

        if list1:
            list1.next = self.mergeTwoLists(list1, list2)

        return list1

