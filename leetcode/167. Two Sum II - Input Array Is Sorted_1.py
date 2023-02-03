"""
    두 수의 합 2
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

    투 포인터
"""
from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while not left == right:
            if numbers[left] + numbers[right] < target:
                left += 1
            elif numbers[left] + numbers[right] > target:
                right -= 1
            else:
                return left + 1, right + 1 # 리턴값 + 1
