"""
    큐를 이용한 스택 구현
    push(x)
    pop() 스택의 첫 번째 요소를 삭제한다.
    top() : 스택의 첫 번째 요소를 가져온다.
    empty() : 스택이 비어 있는지 여부를 리턴한다.

    데크를 사용하여 퍈하게 구현하였다. 큐를 두개써서 구현하는

    1 2 3 4
    push(1)
    q : 1
    재정렬 0번 : 1
    push(2)
    queue : 1 2
    재정렬 1번 : 2 1
    push(3)
    queue : 2 1 3
    재정렬 2번 : 3 2 1

"""
import collections


class MyStack:
    def __init__(self):
        self.q = collections.deque()
    def push(self, x: int) -> None:
        self.q.append(x)
        # 요소를 삽입 후 맨 앞에 두는 상태로 재정렬
        for _ in range(len(self.q) - 1):
            self.q.append(self.q.popleft())
    def pop(self) -> int:
            return self.q.popleft()
    def top(self) -> int:
        return self.q[0]
    def empty(self) -> bool:
        return len(self.q) == 0

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()