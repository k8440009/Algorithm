"""
    집 도둑
    https://leetcode.com/problems/house-robber/

    브루트 포스
    - 타임아웃
"""
from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:

        def _rob(i: int) -> int:
            if i < 0:
                return 0
            return max(_rob(i - 1), _rob(i - 2) + nums[i])

        return _rob(len(nums) - 1)