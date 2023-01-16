"""
    순열
    서로 다른 정수를 입력받아 가능한 모든 순열을 리턴하라
    itertools 모듈 사용

    [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]
"""
import itertools
from typing import List
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return list(map(list, itertools.permutations(nums)))

a = Solution()
nums1 = [1, 2, 3]
print(a.permute(nums1))