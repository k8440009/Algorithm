"""
    두 배열의 교집합
    https://leetcode.com/problems/intersection-of-two-arrays/

    브루트 포스
"""
from typing import List, Set


class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result: Set = set()
        for n1 in nums1:
            for n2 in nums2:
                if n1 == n2:
                    result.add(n1)

        return result