"""
    1 비트의 갯수
    https://leetcode.com/problems/number-of-1-bits/

    1의 갯수 체크
"""


class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count('1')
