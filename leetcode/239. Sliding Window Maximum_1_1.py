"""
    최대 슬라이딩 윈도우
    https://leetcode.com/problems/sliding-window-maximum/

    브루트 포스로 계산
    - 시간 초과
"""
from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return nums

        r = []
        for i in range(len(nums) - k + 1):
            r.append(max(nums[i:i + k]))

        return r
