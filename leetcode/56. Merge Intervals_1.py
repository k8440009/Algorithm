"""
    구간 병합
    https://leetcode.com/problems/merge-intervals/

    정렬하여 병합
"""
from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        for i in sorted(intervals, key=lambda x:x[0]):
            if merged and i[0] <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], i[1])
            else:
                merged += i, # 중첩 리스트로 만들어주는 역할

        return merged
