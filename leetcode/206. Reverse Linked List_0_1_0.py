"""
    역순 연결 리스트
    0. 데이터 출력
"""
from typing import Optional


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(node: ListNode, prev: ListNode = None):
            if not node:
                return prev

            print("===== start =====")
            print("param node={0}".format(node))
            print("param prev={0}".format(prev))

            next, node.next = node.next, prev

            print("next={0}".format(next))
            print("node={0}".format(node))
            print("node.next={0}".format(node.next))

            print("===== end =====")

            return reverse(next, node)

        return reverse(head)


"""
===== start =====
head = [1,2,3,4,5]
param node=ListNode{val: 1, next: ListNode{val: 2, next: ListNode{val: 3, next: ListNode{val: 4, next: ListNode{val: 5, next: None}}}}}
param prev=None
next=ListNode{val: 2, next: ListNode{val: 3, next: ListNode{val: 4, next: ListNode{val: 5, next: None}}}}
node=ListNode{val: 1, next: None}
node.next=None
===== end =====
===== start =====
param node=ListNode{val: 2, next: ListNode{val: 3, next: ListNode{val: 4, next: ListNode{val: 5, next: None}}}}
param prev=ListNode{val: 1, next: None}
next=ListNode{val: 3, next: ListNode{val: 4, next: ListNode{val: 5, next: None}}}
node=ListNode{val: 2, next: ListNode{val: 1, next: None}}
node.next=ListNode{val: 1, next: None}
===== end =====
===== start =====
param node=ListNode{val: 3, next: ListNode{val: 4, next: ListNode{val: 5, next: None}}}
param prev=ListNode{val: 2, next: ListNode{val: 1, next: None}}
next=ListNode{val: 4, next: ListNode{val: 5, next: None}}
node=ListNode{val: 3, next: ListNode{val: 2, next: ListNode{val: 1, next: None}}}
node.next=ListNode{val: 2, next: ListNode{val: 1, next: None}}
===== end =====
===== start =====
param node=ListNode{val: 4, next: ListNode{val: 5, next: None}}
param prev=ListNode{val: 3, next: ListNode{val: 2, next: ListNode{val: 1, next: None}}}
next=ListNode{val: 5, next: None}
node=ListNode{val: 4, next: ListNode{val: 3, next: ListNode{val: 2, next: ListNode{val: 1, next: None}}}}
node.next=ListNode{val: 3, next: ListNode{val: 2, next: ListNode{val: 1, next: None}}}
===== end =====
===== start =====
param node=ListNode{val: 5, next: None}
param prev=ListNode{val: 4, next: ListNode{val: 3, next: ListNode{val: 2, next: ListNode{val: 1, next: None}}}}
next=None
node=ListNode{val: 5, next: ListNode{val: 4, next: ListNode{val: 3, next: ListNode{val: 2, next: ListNode{val: 1, next: None}}}}}
node.next=ListNode{val: 4, next: ListNode{val: 3, next: ListNode{val: 2, next: ListNode{val: 1, next: None}}}}
===== end =====
"""
