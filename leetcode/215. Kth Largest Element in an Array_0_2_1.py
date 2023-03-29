"""
    배열의 K번째 큰 요소
    정렬을 이용한 풀이
"""
import heapq
from typing import List


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = []
        for num in nums:
            heapq.heappush(heap, -num)

        for _ in range(1, k):
            heapq.heappop(heap)

        return -heapq.heappop(heap)

# Input: nums = [3, 2, 1, 5, 6, 4], k = 2
# Output: 5