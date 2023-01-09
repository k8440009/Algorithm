"""
    내가 푼 것
"""
import re


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub('[^a-z0-9]', '', s.lower())
        start, end = 0, len(s) - 1
        print(s)
        while start < len(s) / 2:
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True
a = Solution()
print(a.isPalindrome("A man, a plan, a canal: Panama"))