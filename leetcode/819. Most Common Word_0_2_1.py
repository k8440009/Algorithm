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
import collections
import re
from typing import List


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = re.sub('[^a-z]', " ", paragraph.lower())
        cnt = collections.Counter(paragraph.split())
        ban = collections.defaultdict()

        for word in banned:
            ban[word] = 1

        for key, value in sorted(cnt.items(), key=lambda x: x[1], reverse=True):
            if key not in ban:
                return key

a = Solution()

# paragraph = "Bob!"
# banned = ["hit"]
# print(a.mostCommonWord(paragraph, banned))

paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
print(a.mostCommonWord(paragraph, banned))
