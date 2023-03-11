"""
    중복 문자 제거
    재귀를 이용한 분리
"""
import collections


class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        counter, seen, stack = collections.Counter(s), set(), []

        for char in s:
            # 방문 체크
            counter[char] -= 1
            # 본적이 있으면 pass
            if char in seen:
                continue
            """
                스택의 top 값이 char 보다 크고, counter에 0보다 큰 경우
                seen과 stack 에서 제거한다.
            """
            while stack and char < stack[-1] and counter[stack[-1]] > 0:
                seen.remove(stack.pop())

            stack.append(char)
            seen.add(char)

        return ''.join(stack)
