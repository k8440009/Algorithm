"""
    에너그램
    1. 길이 다름 x
    2. count 같아야함
"""
import collections


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_dict = collections.Counter(s)
        t_dict = collections.Counter(t)

        if len(s) != len(t):
            return False

        for s_key, s_value in s_dict.items():
            if s_key not in t_dict or s_value != t_dict[s_key]:
                return False
        return True
a = Solution()
s = "anagram"
t = "nagaram"
print(a.isAnagram(s, t))

s = "rat"
t = "car"
print(a.isAnagram(s, t))
