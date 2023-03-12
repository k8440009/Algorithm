"""
    원형 큐 구현
    - 배열
"""
class MyCircularQueue:

    def __init__(self, k: int):
        self.q = [None] * k
        self.maxlen = k
        self.front = 0
        self.rear = 0

    # enQueue() : rear 포인터 이동
    def enQueue(self, value: int) -> bool:
        """
            1. rear 포인터 자리에 데이터 삽입
            2. rear 포인터 이동
        """
        if self.q[self.rear] is None:
            self.q[self.rear] = value
            self.rear = (self.rear + 1) % self.maxlen
            return True
        else:
            return False
    # deQueue() : front 포인터 이동
    def deQueue(self) -> bool:
        """
            1. front 포인터 자리에 삭ㅈ[
            2. front 포인터 이동
        """
        if self.q[self.front] is None:
            return False
        else:
            self.q[self.front] = None
            self.front = (self.front + 1) % self.maxlen

            return True

    def Front(self) -> int:
        if self.q[self.front] is None:
            return -1
        else:
            return self.q[self.front]

    def Rear(self) -> int:
        if self.q[self.rear - 1] is None:
            return -1
        else:
            return self.q[self.rear-1]
    def isEmpty(self) -> bool:
        return self.front == self.rear and self.q[self.front] is None
    def isFull(self) -> bool:
        return self.front == self.rear and self.q[self.front] is not None

# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()