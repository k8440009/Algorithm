"""
    에너그램
    1. 정렬
    https://leetcode.com/problems/valid-anagram/description/
    49번 참조
"""


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)