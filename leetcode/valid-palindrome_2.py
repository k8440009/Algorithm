# https://leetcode.com/problems/valid-palindrome/
"""
데크 사용 풀이
"""
from collections import deque

class Solution:
    def isPalindrome(self, s: str) -> bool:
        deq = deque()

        for char in s:
            if char.isalnum():
                deq.append(char.lower())

        while len(deq) > 1:
            if deq.popleft() != deq.pop():
                return False

        return True

a = Solution()
print(a.isPalindrome("A man, a plan, a canal: Panama"))