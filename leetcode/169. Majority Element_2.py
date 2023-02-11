"""
    과반수 엘리먼트
    https://leetcode.com/problems/majority-element/

    다이나믹 프로그래밍
    - 메모이제이션
"""
import collections
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts = collections.defaultdict(int)
        for num in nums:
            if counts[num] == 0:
                counts[num] = nums.count(num)

            if counts[num] > len(nums) // 2:
                return num
