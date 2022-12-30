"""
    순열
    서로 다른 정수를 입력받아 가능한 모든 순열을 리턴하라
    dfs 순열 생성
"""
from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        prev_elements = []

        def dfs(elements):
            # 리프노드일 때 결과 추가
            if len(elements) == 0:
                result.append(prev_elements[:])

            # 순열 생성 재귀 호출
            for e in elements:
                next_elements = elements[:]
                next_elements.remove(e)
                prev_elements.append(e)
                dfs(next_elements)
                prev_elements.pop()

        dfs(nums)
        return result