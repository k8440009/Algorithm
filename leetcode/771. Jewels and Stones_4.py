"""
    보석과 돌
    파이썬 다운 방식

    stone for stone in stones
    ['a', 'A', 'A', 'b', 'b', 'b', 'b']

    stone in jewels for stone in stones
    [True, True, True, False, False, False, False]
"""
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(stone in jewels for stone in stones)