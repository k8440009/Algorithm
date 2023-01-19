"""
    빗물 트래핑
    https://leetcode.com/problems/trapping-rain-water/
"""
from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        """
        가장 높은 막대는 높고 낮은과 무관하게 전체 부피에 영향을 끼치지 않으면서
        그저 왼쪽과 오른쪽을 가르는 장벽 역할을 한다.

        최대 높이의 막대까지 각각 좌우 기동 최대 높이가 현재 높이와의 차이만큼
        물 높이 volume을 각각 더해나간다.
        """
        volume = 0
        left, right = 0, len(height) - 1
        left_max, right_max = height[left], height[right]

        while left < right:
            left_max, right_max = max(height[left], left_max), max(height[right], right_max)
            # 왼쪽이 더 작은거나 같은 경우
            if left_max <= right_max:
                volume += left_max - height[left]
                left += 1
            # 오른쪽이 작은 경우
            else:
                volume += right_max - height[right]
                right -= 1
        return volume


a = Solution()
height = [1, 0, 2, 0, 1]
#height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
print(a.trap(height))
