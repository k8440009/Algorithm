"""
    상위 K빈도 요소
    파이썬 다운 방식
"""
import collections
from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        print(collections.Counter(nums).most_common(k))
        print(zip(*collections.Counter(nums).most_common(k)))
        print(list(zip(*collections.Counter(nums).most_common(k))))
        return list(zip(*collections.Counter(nums).most_common(k)))[0]

a = Solution()
print(a.topKFrequent([1,1,1,2,2,3], 2))