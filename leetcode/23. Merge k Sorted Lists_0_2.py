"""
    k개 정렬 리스트 병합
    https://leetcode.com/problems/merge-k-sorted-lists/
"""
import heapq
from typing import Optional, List


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        root = result = ListNode(None)
        # 리스트에 삽입
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i, lists[i]))

        while heap:
            node = heapq.heappop(heap)
            idx = node[1]
            result.next = node[2]

            result = result.next

            if result.next:
                heapq.heappush(heap, (result.next.val, idx, result.next))

        return root.next
