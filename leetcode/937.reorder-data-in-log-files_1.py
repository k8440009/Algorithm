"""
    937. 로그 파일 재정렬
    - 람다식을 사용한 간단한 풀이

    https://leetcode.com/problems/reorder-data-in-log-files/
"""

from typing import List

class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letters, digits = [], []
        for log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)
        # 2개의 키를 람다 표현식으로 정렬
        letters.sort(key=lambda x : (x.split()[1:], x.split()[0]))

        return letters + digits

a = Solution()
logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
print(a.reorderLogFiles(logs))