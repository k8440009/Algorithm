# https://leetcode.com/problems/valid-palindrome/
"""
문제 설명
1. 문자열은 펠린드롬이다. 펠린 드롬은 앞으로 읽을 때와 뒤에서 읽을 때 모두 같다.
2. 모든 대문자는 소문자로, 영숫자 이외에는 모두 제거한다.
3. 영숫자를 포함한다.

일반 풀이
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:

        strs = []
        for char in s:
            if char.isalnum():
                strs.append(char.lower())

        while len(strs) > 1:
            if strs.pop(0) != strs.pop():
                return False

        return True

a = Solution()
print(a.isPalindrome("A man, a plan, a canal: Panama"))