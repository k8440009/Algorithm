"""
    그룹 에너그램
"""
import collections
from typing import List
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)

        for word in strs:
            anagrams[''.join(sorted(word))].append(word)
        return list(anagrams.values())

a = Solution()
strs = ["eat","tea","tan","ate","nat","bat"]
print(a.groupAnagrams(strs))