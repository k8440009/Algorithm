# https://leetcode.com/problems/valid-palindrome/
"""
문자열 슬라이싱
"""
import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        # 정규식으로 불필요한 문자열 필터링
        s = re.sub('[^a-z0-9]', '', s)
        return s == s[::-1]

a = Solution()
print(a.isPalindrome("A man, a plan, a canal: Panama"))