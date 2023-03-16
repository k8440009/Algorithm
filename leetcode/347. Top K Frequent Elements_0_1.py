"""
    상위 K빈도 요소
    https://leetcode.com/problems/top-k-frequent-elements/

    상위 k번 이상 등장하는 요소를 추출하라

    Counter 사용
"""
import collections
import heapq
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = collections.Counter(nums)
        # Counter({1: 3, 2: 2, 3: 1})
        freq_heap = []
        # key : 빈도수 , value : 값
        for num in freq:
            heapq.heappush(freq_heap, (-freq[num], num))

        result = []
        for _ in range(k):
            result.append(heapq.heappop(freq_heap)[1])

        return result
