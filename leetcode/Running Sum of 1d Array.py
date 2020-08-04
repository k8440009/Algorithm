class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        total = 0
        sums = []
        for data in nums:
            total += data
            sums.append(total)
        return sums