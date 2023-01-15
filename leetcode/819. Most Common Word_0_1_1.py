"""
가장 흔한 단어

1. 금지된 단어와, 단락이 주어진다. 금지되지 않는 가장 흔한 단어를 반환해라
2. 금지 단어가 아닌, 가장 작은 단어 한개는 보장되며, 정답은 유니크하다.
3. 단락안에 있는 단어는 대소문자가 구분이 없으며, 정답은 반드시 소문자로 반환되어야한다.
4. 구두점(마침표, 쉼표 등) 또한 무시한다.

paragraph : 단락
case-insensitive : 대소문자 구분이 없다.

https://leetcode.com/problems/most-common-word/submissions/
"""
import re
from typing import List


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        # 정규식을 사용하여 영문자 이외는 모두 space로 변경한다.
        # 단락을 모두 소문자로 바꾸고, 리스트로 만든다.
        # list = re.sub('[^,.]', ' ', paragraph.lower()).split()
        words = re.sub('[^a-z]', ' ', paragraph.lower()).split()

        dic = dict()
        for word in words:
            # 금지 단어 제거
            flag = False
            for ban in banned:
                if ban == word:
                    flag = True
                    break

            if flag:
                continue

            if word in dic:
                dic[word] = dic.get(word) + 1
            else:
                dic[word] = 1
        d1 = sorted(dic.items(), key=lambda x: x[1], reverse=True)
        return d1[0][0] # 딕셔너리를 items로 가져오면 [()](리스트 + 튜플형태이다)

# 1
# paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
# banned = ["hit"]

# 2
paragraph = "Bob!"
banned= ["hit"]
a = Solution()
print(a.mostCommonWord(paragraph, banned))
