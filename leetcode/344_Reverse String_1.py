"""
    문자열 뒤집기
    - 투 포인터

    https://leetcode.com/problems/reverse-string/
"""
from typing import List
class Solution:
    def reverseString(self, s: List[str]) -> None:
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
