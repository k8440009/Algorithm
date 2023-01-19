"""
    빗물 트래핑
    https://leetcode.com/problems/trapping-rain-water/

    투 포인터
"""
from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        left_max, right_max = height[left], height[right]
        volume = 0
        while left < right:
            left_max, right_max = max(height[left], left_max), max(height[right], right_max)

            if left_max <= right_max:
                volume += left_max - height[left]
                left += 1
            else:
                volume += right_max - height[right]
                right -= 1
        return volume

a = Solution()
# height = [1, 0, 2, 0, 1]
height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
print(a.trap(height))