# https://leetcode.com/problems/valid-palindrome/
"""
데크 사용 풀이
"""
import collections
from typing import Deque


class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 자료형 데크로 선언
        strs: Deque = collections.deque()

        for char in s:
            if char.isalnum():
                strs.append(char.lower())

        while len(strs) > 1:
            if strs.popleft() != strs.pop():
                return False

        return True


a = Solution()
print(a.isPalindrome("A man, a plan, a canal: Panama"))