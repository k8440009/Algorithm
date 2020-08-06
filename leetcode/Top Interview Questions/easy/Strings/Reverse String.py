# Reverse String
# https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        tmp = []
        for i in reversed(range(len(s))):
            tmp.append(s[i])
        for i in range(len(tmp)):
            s[i] = tmp[i]