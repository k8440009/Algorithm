"""
    부분 문자열이 포함된 최소 윈도우
    https://leetcode.com/problems/minimum-window-substring/

    모든 윈도우 크기를 브루트 포스로 탐색
    - 시간 초과
"""
from typing import List


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        def contains(s_substr_lst: List, t_lst: List):
            for t_elem in t_lst:
                if t_elem in s_substr_lst:
                    s_substr_lst.remove(t_elem)
                else:
                    return False
            return True

        if not s or not t:
            return ''

        window_size = len(t)

        for size in range(window_size, len(s) + 1):
            for left in range(len(s) - size + 1):
                s_substr = s[left:left + size]
                if contains(list(s_substr), list(t)):
                    return s_substr

        return ''
