"""
    보석과 돌
    https://leetcode.com/problems/jewels-and-stones/

    파이썬 방식
"""

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(stone in jewels for stone in stones)
