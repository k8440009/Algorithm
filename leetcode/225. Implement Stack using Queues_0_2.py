"""
    큐를 이용한 스택 구현
    https://leetcode.com/problems/implement-stack-using-queues/

    큐
"""
import collections


class MyStack:

    def __init__(self):
        self.q = collections.deque()

    def push(self, x: int) -> None:
        # 길이 -1 만큼 다시 넣는 것으로 재정렬 한다.
        self.q.append(x)
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())

    def pop(self) -> int:
        return self.q.popleft();

    def top(self) -> int:
        return self.q[0]

    def empty(self) -> bool:
        return len(self.q) == 0