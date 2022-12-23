"""
    보석과 돌
    defaultdict를 이용한 비교 생략
"""
import collections


class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        freqs = collections.defaultdict(int)
        count = 0

        # 비교 없이 돌의 빈도수 계산
        for char in stones:
            freqs[char] += 1

        # 비교 없이 보석 빈도수 합산
        for char in jewels:
            count += freqs[char]

        return count