"""
가장 흔한 단어
- 리스트 컴프리핸션
- 람다식
- 정규식
- 딕셔너리
https://leetcode.com/problems/most-common-word/submissions/
"""
import collections
import re
from typing import List


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        """
            \w는 word 문자를 뜻하며, ^는 not을 의마한다.
            따라서 정규식은 단어 문자가 아닌 모든 문자를 공백으로 치환한다.
        """
        words = [word for word in re.sub('[^\w]', ' ', paragraph)
            .lower().split()
                if word not in banned]

        counts = collections.Counter(words)
        # 가장 흔하게 등장하는 단어의 첫 번째 인덱스 리턴
        print(counts.most_common(1))
        return counts.most_common(1)[0][0]
