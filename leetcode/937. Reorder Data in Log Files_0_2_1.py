"""
    937. 로그 파일 재정렬
    - 로그 배열을 받았다. 각각의 로그는 구분 문자로 공백을 사용하여, 첫번째 단어는 식별자다.
    - 두개의 타입의 로그가 있다.
        - 문자 로그 : 모든 단어(식별자 제외)가 영어 소문자이다.
        - 숫자 로그 : 모든 단어(식별자 제외)가 숫자이다.
    - 이 로그는 아래와 같은 방식으로 재 정렬 되어야한다.
        1. 문자 로그가 숫자 로그보다 앞에 온다.
        2. 문자 로그는 사전식으로 정렬되어 있다. 그들의 내용이 동일 할 경우, 식별자의 사전식 순서로 정렬되어야한다.
        - 기본으로는 내용으로 정렬, 동일한 경우 식별자로 정렬
        3. 숫자로그는 입력 순서대로한다.
        4. 식별자는 중복 가능하다.

    https://leetcode.com/problems/reorder-data-in-log-files/

    lexicographically : 사전식 순서
    delimited : 구분문자
"""
import collections
from typing import List


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letters, digits = [], []
        for log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)
        letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))

        return letters + digits


a = Solution()
# logs = ["dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"]
# output = ["let1 art can", "let3 art zero", "let2 own kit dig", "dig1 8 1 5 1", "dig2 3 6"]
# print(a.reorderLogFiles(logs))
#
# logs = ["a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"]
# output = ["g1 act car", "a8 act zoo", "ab1 off key dog", "a1 9 2 3 1", "zo4 4 7"]
# print(a.reorderLogFiles(logs))


logs = ["1 n u", "r 527", "j 893", "6 14", "6 82"]
# ["1 n u","r 527","j 893","6 82"]
print(a.reorderLogFiles(logs))
