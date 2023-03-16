"""
    보석과 돌
    https://leetcode.com/problems/jewels-and-stones/

    해시 테이블, coutner
"""
import collections


class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        freqs = collections.Counter(stones)
        counter = 0
        for jewel in jewels:
            counter += freqs[jewel]

        return counter
