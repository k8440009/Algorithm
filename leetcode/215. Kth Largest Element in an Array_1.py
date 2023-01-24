"""
    배열의 K번째 큰 요소
    heapq 모듈 이용
"""
import heapq
from typing import List
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = list()
        for n in nums:
            heapq.heappush(heap, -n)

        for _ in range(1, k):
            heapq.heappop(heap)


        return -heapq.heappop(heap)