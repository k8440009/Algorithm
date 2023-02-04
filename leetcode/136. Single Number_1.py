"""
    싱글넘버
    https://leetcode.com/problems/single-number/

    XOR 풀이
"""
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            result ^= num

        return result
