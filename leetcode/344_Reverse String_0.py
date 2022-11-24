"""
    문자열 뒤집기
    - 리스트 reverse 풀아

    https://leetcode.com/problems/reverse-string/
"""
from typing import List
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s.reverse()
