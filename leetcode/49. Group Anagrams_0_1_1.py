"""
    그룹 애너그램
    정렬하여 딕셔너리에 추가
    - 단어자체를 정렬하면, 서로 같은 값을 갖게 된다.
    - 이를 다시 키로 사용하여 리스트를 넣는다.

    1. 데이터 처리
    1) 일반 문자열은 정렬로 처리된다.
    2) 공백은 어떻게 처리 할 것인가?
    - 공백을 정렬하면 '' 으로 처리된다. 딕셔너리에도 정상적으로 들어간다.

    https://leetcode.com/problems/group-anagrams/
"""
import collections
from typing import List
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)

        for word in strs:
            anagrams[''.join(sorted(word))].append(word)
        return list(anagrams.values())

a = Solution();
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(a.groupAnagrams(strs))

strs = ["", ""]
print(a.groupAnagrams(strs))

# [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]
# [['eat tea ate'], ['tan nat'], ['bat']]