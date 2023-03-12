"""
    이중 연결 리스트를 이용한 데크 구현
    이중 연결 리스트
"""


class MyCircularDeque:

    def __init__(self, k: int):
        self.head, self.tail = ListNode(None), ListNode(None)
        self.max_len, self.now_len = k, 0
        self.head.right, self.tail.left = self.tail, self.head

    # 이중 연결 리스트 노드에 삽입
    def _add(self, left_node:ListNode, new_node:ListNode):
        right_node = left_node.right
        left_node.right = new_node
        new_node.left, new_node.right = left_node, right_node
        right_node.left = new_node

    # 이중 연결 리스트 노드에 삽입
    def _del(self, del_node:ListNode):
        n = del_node.right.right
        del_node.right = n
        n.left = del_node

    def insertFront(self, value: int) -> bool:
        if self.max_len == self.now_len:
            return False

        self.now_len += 1
        self._add(self.head, ListNode(value))

        return True

    def insertLast(self, value: int) -> bool:
        if self.max_len == self.now_len:
            return False

        self.now_len += 1
        self._add(self.tail.left, ListNode(value))
        return True

    def deleteFront(self) -> bool:
        if self.now_len == 0:
            return False

        self.now_len -=1
        self._del(self.head)
        return True

    def deleteLast(self) -> bool:
        if self.now_len == 0:
            return False

        self.now_len -=1
        self._del(self.tail.left.left)
        return True

    def getFront(self) -> int:
        return self.head.right.val if self.now_len else -1

    def getRear(self) -> int:
        return self.tail.left.val if self.now_len else -1

    def isEmpty(self) -> bool:
        return self.now_len == 0

    def isFull(self) -> bool:
        return self.now_len == self.max_len


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()