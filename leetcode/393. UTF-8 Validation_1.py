"""
    UTF-8 검증
    https://leetcode.com/problems/utf-8-validation/

    첫 바이트를 기준으로 한 판별
    - 6장 162 페이지 참조
"""
from typing import List


class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        # 문자 바이트 만큼 10으로 시작 판별
        def check(size):
            for i in range(start + 1, start + size + 1):
                if i >= len(data) or (data[i] >> 6) != 0b10:
                    return False
            return True

        start = 0
        while start < len(data):
            # 첫 바이트 기준 총 문자 바이트 판별
            first = data[start]
            if (first >> 3) == 0b11110 and check(3):  ## 4바이트
                start += 4
            elif (first >> 4) == 0b1110 and check(2):  ## 3바이트
                start += 3
            elif (first >> 5) == 0b110 and check(1):  ## 2바이트
                start += 2
            elif (first >> 7) == 0:  # 1바이트
                start += 1
            else:
                return False

        return True
