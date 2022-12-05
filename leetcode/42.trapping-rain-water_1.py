"""
https://leetcode.com/problems/trapping-rain-water/
"""
from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0

        volume = 0
        left, right = 0, len(height) - 1
        left_max, right_max = height[left], height[right]

        while left < right :
            left_max, right_max = max(height[left], left_max), max(height[right], right_max)
            print("left={0}, right={1}".format(left, right))
            print("left_max={0}, right_max={1}".format(left_max, right_max))
            # 더 높은 쪽을 향해 투 포인터 이동
            if left_max <= right_max:
                print("bf_volume={0}".format(volume))
                volume += left_max - height[left]
                left += 1
                print("volume1={0}".format(volume))
            else :
                print("bf_volume={0}".format(volume))
                volume += right_max - height[right]
                right -= 1
                print("volume2={0}".format(volume))
        return volume

a = Solution()
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(a.trap(height))