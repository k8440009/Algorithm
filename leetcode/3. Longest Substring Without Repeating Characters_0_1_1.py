"""
    Given a string s, find the length of the longest
    substring without repeating characters.

    ## 나의 풀이방법
    - 재귀, 스택
"""
class Solution:
    def longest_substring(self, substr: str) -> str:
        for char in sorted(set(substr)):
            suffix = substr[substr.index(char):]

            print(suffix)
            # if set(substr) == set(suffix):
                # return char + self.longest_substring(suffix)

        return ''

    def lengthOfLongestSubstring(self, s: str) -> int:
        data = self.longest_substring(s)

        return len(data)

a = Solution()
s = "abcabcbb"
print(a.lengthOfLongestSubstring(s))
# s = "bbbbb"
# print(a.lengthOfLongestSubstring(s))
# s = "pwwkew"
# print(a.lengthOfLongestSubstring(s))