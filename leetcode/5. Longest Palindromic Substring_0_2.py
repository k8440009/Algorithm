"""
    가장 긴 문자열
    https://leetcode.com/problems/longest-palindromic-substring/description/
    - 중앙을 기준으로 2개(짝수), 3개(홀수) 부분문자열을 늘린다.
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(left:int, right:int) -> str:
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1

            return s[left+1:right]

        # 1. 항상 정답
        if len(s) < 2 or s == s[::-1]:
            return s

        result = ''
        # 2개, 3개를 기준으로 증가
        for i in range(len(s)):
            result = max(result,
                         expand(i, i + 1),
                         expand(i, i + 2),
                         key=len)
        return result


# a = Solution()
# s = "babad"
# print(a.longestPalindrome(s))