"""
    보석과 돌
    Counter로 계산 생략
"""
import collections


class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        freqs = collections.Counter(stones)
        count = 0
        # 비교 없이 보석  빈도수 합산
        for char in jewels:
            count += freqs[char]
        return count