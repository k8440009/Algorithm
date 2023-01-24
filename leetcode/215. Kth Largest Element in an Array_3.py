"""
    배열의 K번째 큰 요소
    heapq 모듈의 nlargetst 이용
"""
import heapq
from typing import List
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1]