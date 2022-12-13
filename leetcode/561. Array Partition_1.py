"""
    배열 파티션 1
    1. 오름차순 풀이
"""
from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        sum = 0
        pair = []
        nums.sort()
        for n in nums:
            # 앞에서부터 오름차순으로 페어를 만들어 합 계산
            pair.append(n)
            if len(pair) == 2:
                sum += min(pair)
                pair = []
        return sum

a = Solution()
nums = [1,4,3,2]
print(a.arrayPairSum(nums))