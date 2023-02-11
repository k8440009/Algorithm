"""
    괄호를 삽입하는 여러 가지 방법
    https://leetcode.com/problems/different-ways-to-add-parentheses/

    분할정복
    - 다양한 조합 생성
"""
from typing import List


class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        def compute(left, right, op):
            results = []

            for l in left:
                for r in right:
                    results.append(eval(str(l) + op + str(r))) # 문자열을 파싱하고, 파이썬 표현식으로 처리

            return results

        if expression.isdigit():
            return [int(expression)]

        results = []
        for index, value in enumerate(expression):
            if value in "-+*":
                left = self.diffWaysToCompute(expression[:index])
                right = self.diffWaysToCompute(expression[index + 1:])

                results.extend(compute(left, right, value))

        return results
