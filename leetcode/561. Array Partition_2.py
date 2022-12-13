"""
    배열 파티션 1
    2. 짝수 값 계산
"""
from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        sum = 0
        nums.sort()

        for i, n in enumerate(nums):
            # 짝수 번째 값의 합 계산
            if i % 2 == 0:
                sum += n
        return sum

a = Solution()
nums = [1,4,3,2]
print(a.arrayPairSum(nums))