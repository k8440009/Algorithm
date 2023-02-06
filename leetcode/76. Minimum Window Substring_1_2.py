"""
    부분 문자열이 포함된 최소 윈도우
    https://leetcode.com/problems/minimum-window-substring/

    모든 윈도우 크기를 브루트 포스로 탐색
    - 투 포인터, 슬라이딩 윈도우로 최적화
"""
import collections
from typing import List


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = collections.Counter(t)
        missing = len(t)
        left = start = end = 0

        # 오른쪽 포인터 이동
        for right, char in enumerate(s, 1):
            missing -= need[char] > 0
            need[char] -= 1

            # 필요 문자가 0이면 왼쪽 포인터 이동 판단
            if missing == 0:
                while left < right and need[s[left]] < 0:
                    need[s[left]] += 1
                    left += 1

                if not end or right - left <= end - start:
                    start, end = left, right
                    need[s[left]] += 1
                    missing += 1
                    left += 1

        return s[start:end]
