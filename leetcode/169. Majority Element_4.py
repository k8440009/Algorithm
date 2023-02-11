"""
    과반수 엘리먼트
    https://leetcode.com/problems/majority-element/

    파이썬다운 방식
"""
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return sorted(nums)[len(nums) // 2]
