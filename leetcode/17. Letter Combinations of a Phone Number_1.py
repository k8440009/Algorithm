"""
    전화 번호 문자 조합

    2에서 9까지 숫자가 주어졌을 때 전화 번호로 조합가능한 모든 문자를 출력하라
"""
from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(index, path):
            # 끝까지 탐색하면 백 트래킹
            if len(path) == len(digits):
                result.append(path)
                return

            # 입력값 자릿수 단위 반복
            for i in range(index, len(digits)):
                # 숫자에 해당하는 모든 문자열 반복
                for j in dic[digits[i]]:
                    dfs(i + 1, path + j)

        # 예외처리
        if not digits:
            return []

        dic = {"2" : "abc", "3" : "def", "4" : "ghi", "5" : "jkl",
               "6" : "mno", "7" : "pqrs", "8" : "tuv", "9" : "wxyz"}
        result = []
        dfs(0, "")

        return result