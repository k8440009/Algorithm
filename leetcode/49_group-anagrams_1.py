"""
    https://leetcode.com/problems/group-anagrams/
"""
import collections
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)
        for word in strs:
            # 정렬하여 딕셔너리에 추가
            anagrams[''.join(sorted(word))].append(word)
        return list(anagrams.values())
a = Solution();
"""
    1.
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    [["bat"],["nat","tan"],["ate","eat","tea"]]
"""
"""
"""
# strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
strs = [""]
print(a.groupAnagrams(strs))

# [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]
# [['eat tea ate'], ['tan nat'], ['bat']]