"""
    일일 온도
    https://leetcode.com/problems/daily-temperatures/

    현재의 인덱스를 계속 스택에 쌓아 두다가, 이전보다 상승하는 지점에서 현재 온도와 스택에 쌓아둔 인덱스 지점의 온도 차이를 배교해서
    더 높다면 다음과 같이 스택의 값을 팝으로 꺼내고, 현재 인덱스와 스택에 쌓아둔 인덱스의 차이를 정답으로 처리한다.
"""
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0] * len(temperatures)
        stack = []

        for i, cur in enumerate(temperatures):
            # 현재 온도가 스택 값보다 높다면 정답 처리
            while stack and cur > temperatures[stack[-1]]:
                last = stack.pop()
                answer[last] = i - last
            stack.append(i)

        return answer