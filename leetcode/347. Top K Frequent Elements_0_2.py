"""
    상위 K빈도 요소
    https://leetcode.com/problems/top-k-frequent-elements/

    파이썬 다운 방식
    1. most_common(k) => [(1, 3), (2, 2)]
    2. 아스테리스크와 zip을 사용하여 list 만들면 [(1, 2), (3, 2)]
"""
import collections
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return list(zip(*collections.Counter(nums).most_common(k)))[0]