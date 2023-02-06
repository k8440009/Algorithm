"""
    최대 슬라이딩 윈도우
    https://leetcode.com/problems/sliding-window-maximum/

    브루트 포스를 큐를 이용하여 시간 개선
    - 시간 초과
    https://github.com/onlybooks/algorithm-interview/issues/66
"""
import collections
from typing import List


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        results = []
        window = collections.deque()
        current_max = float('-inf')
        for i, v in enumerate(nums):
            window.append(v)

            if i < k - 1:
                continue

            # 새로 추가된 값이 기존 최댓값보다 큰 경우 교체
            if current_max == float('-inf'):
                current_max = max(window)
            elif v > current_max:
                current_max = v

            results.append(current_max)

            # 최댓값이 윈도우에서 빠지면 초기화
            if current_max == window.popleft():
                current_max = float('-inf')

        return results