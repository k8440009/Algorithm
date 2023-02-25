"""
    1. 세 수의 합
    https://leetcode.com/problems/3sum/

    세 수의 합이 0이 되도룩 해라

    투 포인터
"""
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()

        for i in range(len(nums) - 2):
            # 중복 pass
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            # 간격 좁혀 나가면서 sum 계산
            left, right = i + 1, len(nums) - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]

                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    # sum이 0 인 경우 정답 및 스킵 처리
                    result.append([nums[i], nums[left], nums[right]])
                    # left, right 양 옆으로 동일한 값이 있을 수 있으므로 스킵 처리
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1

        return result
