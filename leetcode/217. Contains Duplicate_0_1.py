"""
    중복 찾기
    https://leetcode.com/problems/contains-duplicate/

    딕셔너리 사용
"""
import collections
from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dic = collections.defaultdict(int)

        for i, num in enumerate(nums):
            if dic[num] == 0:
                dic[num] = 1
            else:
                return True

        return False
