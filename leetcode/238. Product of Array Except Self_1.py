"""
    자신을 제외한 배열의 곱
    https://leetcode.com/problems/product-of-array-except-self/

    왼쪽 곱셈 결과에 오른쪽 값을 차려대로 곱셈

    배열을 입력 받아 output[i]가 자신을 제외한 나머지 모든 요소의 곱셈 결과가 되도록 출력하라

    뭔 소린지 모르겠고 풀이방법을 외운다.
"""
from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        out = []
        p = 1
        # 왼쪽 곱셈
        for i in range(0, len(nums)):
            out.append(p)
            p = p * nums[i]
        p = 1
        # range (x, y, z) : z는 증분을 지정하는 파라메터
        for i in range(len(nums) - 1, 0 - 1, -1):
            out[i] = out[i] * p
            p = p * nums[i]
        return out
a = Solution()
nums = [1,2,3,4]
print(a.productExceptSelf(nums))