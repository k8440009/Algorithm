class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        for _ in range(k % len(nums)) :
            tmp = nums[len(nums) - 1]
            nums.pop()
            nums.insert(0, tmp)
        