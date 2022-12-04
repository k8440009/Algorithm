"""
    1. 두 수의 합
    1) 기본 로직
    - 딕셔너리에 데이터 저장
    - 딕셔너리에 해당 값이 존재하고, 그것이 자기 자신이 아닌경우
    2) 조회 구조 개선
    https://leetcode.com/problems/two-sum/
"""
from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_map = {}
        # 하나의 for 문으로 통합
        for i, num in enumerate(nums):
            if target - num in nums_map:
                # 나중에 선택하는 방식
                return [nums_map[target - num], i]
            nums_map[num] = i

a = Solution()
nums = [2,7,11,15]
target = 9
print(a.twoSum(nums, target))