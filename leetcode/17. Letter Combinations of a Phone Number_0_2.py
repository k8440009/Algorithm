"""
    전화 번호 문자 조합
    https://leetcode.com/problems/letter-combinations-of-a-phone-number/
"""
from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(index, words):
            if index >= len(digits):
                result.append(words)
                return

            for w in dic[digits[index]]:
                dfs(index + 1, words+w)

        if not digits:
            return []

        dic = {
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz"
        }

        result = []
        dfs(0, "")

        return result





