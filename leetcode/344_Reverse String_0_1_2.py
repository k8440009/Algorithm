"""
    문자열 뒤집기
    https://leetcode.com/problems/reverse-string/
"""
from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
            Do not return anything, modify s in-place instead.
            메모리만 수정
        """
        s.reverse()

