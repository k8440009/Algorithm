"""
    중복 찾기
    https://leetcode.com/problems/contains-duplicate/

    set 사용
"""
from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))
