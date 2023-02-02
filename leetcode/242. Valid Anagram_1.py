"""
    유효한 애너그램
    https://leetcode.com/problems/valid-anagram/
    정렬을 이용한 비교
"""
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)