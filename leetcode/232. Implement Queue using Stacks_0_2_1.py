"""
    스택을 이용한 큐 구현
"""
import collections


class MyQueue:

    def __init__(self):
        self.input = collections.deque()
        self.output = collections.deque()

    def push(self, x: int) -> None:
        # 요소 x를 큐 마지막에 삽입한다.
        self.input.append(x)
    def pop(self) -> int:
        # 큐 처음에 있는 요소를 제거한다.
        self.peek()
        return self.output.pop()

    def peek(self) -> int:
        # 큐 처음에 있는 요소를 조회한다.

        # output이 없으면 재입력
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())
        return self.output[-1]

    def empty(self) -> bool:
        # 큐가 비어 있는지 확인한다.
        return len(self.input) == 0 and len(self.output) == 0

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()