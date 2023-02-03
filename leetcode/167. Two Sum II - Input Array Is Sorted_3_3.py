"""
    두 수의 합 2
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

    biset 모듈 + 슬라이싱 제거 => 최적화 완료
"""
import bisect
from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for k, v in enumerate(numbers):
            expected = target - v
            i = bisect.bisect_left(numbers, expected, k + 1)
            if i < len(numbers) and numbers[i] == expected:
                return k + 1, i + 1
