"""

"""
from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0] * len(temperatures)
        stack = []

        for i, cur in enumerate(temperatures):
            # 현재 온도가 스택 온도보다 높은 경우
            while stack and cur > temperatures[stack[-1]]:
                last = stack.pop()
                answer[last] = i - last
            stack.append(i)

        return answer
a = Solution();
print(a.dailyTemperatures([73,74,75,71,69,72,76,73]))

"""
answer = [1,1,4,2,1,1,0,0]
"""