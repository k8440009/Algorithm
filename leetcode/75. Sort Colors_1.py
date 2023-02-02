"""
    색 정렬
    https://leetcode.com/problems/sort-colors/

    네덜란드 국기 문제를 응용한 풀이
"""
from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        red, white, blue = 0, 0, len(nums)

        while white < blue:
            if nums[white] < 1:
                nums[red], nums[white] = nums[white], nums[red]
                white += 1
                red += 1
            elif nums[white] > 1:
                blue -= 1
                nums[white], nums[blue] = nums[blue], nums[white]
            else:
                white += 1
