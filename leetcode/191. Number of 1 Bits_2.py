"""
    1 비트의 갯수
    https://leetcode.com/problems/number-of-1-bits/

    비트 연산
    - 원래 데이터 and 원래 데이터 - 1 => 1 비트씩 제거
"""


class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            # 1을 뺀 값과 AND 연산 횟수 측정
            n &= n - 1
            count += 1

        return count
