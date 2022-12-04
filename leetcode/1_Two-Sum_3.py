"""
    1. 두 수의 합
    - 딕셔너리에 데이터 저장
    - 딕셔너리에 해당 값이 존재하고, 그것이 자기 자신이 아닌경우
    https://leetcode.com/problems/two-sum/
"""
from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_map = {}
        # 키와 값을 바꿔서 딕셔너리로 저장
        for i, num in enumerate(nums):
            nums_map[num] = i
        # 타겟에서 첫 번째 수를 뺀 결과를 키로 조회
        for i, num in enumerate(nums):
            # 딕셔너리에 해당 값이 존재하고, 그것이 자기 자신이 아닌경우
            if target - num in nums_map and i != nums_map[target - num]:
                return [i, nums_map[target - num]]

a = Solution()
nums = [2,7,11,15]
target = 9
print(a.twoSum(nums, target))