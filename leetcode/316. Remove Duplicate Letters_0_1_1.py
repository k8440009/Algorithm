"""
    중복 문자 제거
    재귀를 이용한 분리
"""


class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        for char in sorted(set(s)):
            suffix = s[s.index(char):]

            ## 전체 집합과 접미사 집합이 동일 할 시
            if set(s) == set(suffix):
                return char + self.removeDuplicateLetters(suffix.replace(char, ''))
        return ''
