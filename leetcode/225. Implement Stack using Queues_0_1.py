import collections


class MyStack:

    def __init__(self):
        self.q = collections.deque() # 데크를 큐 처럼 사용한다.
    def push(self, x: int) -> None:
        """
            1. append()
            2. 길이 -1 만큼
        """
        self.q.append(x)
        # print(self.q)
        # print("===== sort START =====")
        for _ in range(len(self.q) - 1):
            data = self.q.popleft()
            # print("sort data={0}".format(data))
            self.q.append(data)
        # print("===== sort END =====")
    def pop(self) -> int:
        return self.q.popleft();
    def top(self) -> int:
        return self.q[0]
    def empty(self) -> bool:
        return len(self.q) == 0
# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(1)
# obj.push(2)
# obj.push(3)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

