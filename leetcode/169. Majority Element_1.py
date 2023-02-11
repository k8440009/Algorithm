"""
    과반수 엘리먼트
    https://leetcode.com/problems/majority-element/

    브루트 포스로 과반수 비교
    - 타임 아웃
"""
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        for num in nums:
            if nums.count(num) > len(nums) // 2:
                return num
