"""
    1. 세 수의 합
    - 브루트 포스

    [결과]
    time out
https://leetcode.com/problems/3sum/
"""

from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        results = []
        nums.sort()

        # n ^ 3
        for i in range(len(nums) - 2):
            # 중복 pass
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, len(nums) - 1):
                # 중복 pass
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                for k in range(j + 1, len(nums)):
                    # 중복 pass
                    if k > j + 1 and nums[k] == nums[k - 1]:
                        continue

                    if nums[i] + nums[j] + nums[k] == 0:
                        results.append([nums[i], nums[j], nums[k]])

        return results

a = Solution()
nums = [-1,0,1,2,-1,-4]
print(a.threeSum(nums))