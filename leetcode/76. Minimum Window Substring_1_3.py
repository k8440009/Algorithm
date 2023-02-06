"""
    부분 문자열이 포함된 최소 윈도우
    https://leetcode.com/problems/minimum-window-substring/

    모든 윈도우 크기를 브루트 포스로 탐색
    - Counter로 좀 더 편리한 풀이 하지만 느린 풀이
"""
import collections
from typing import List


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_count = collections.Counter(t)
        current_count = collections.Counter()

        start = float('-inf')
        end = float('inf')

        left = 0
        # 오른쪽 포인터 이동
        for right, char in enumerate(s, 1):
            current_count[char] += 1

            # AND 연산으로 왼쪽 포인터 이동판단
            while current_count & t_count == t_count:
                if right - left < end - start:
                    start, end = left, right
                current_count[s[left]] -= 1
                left += 1

        return s[start:end] if end - start <= len(s) else ''