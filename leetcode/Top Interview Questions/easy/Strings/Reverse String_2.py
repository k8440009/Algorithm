# Reverse String
# https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        '''
        my solution
        left, right = 0, len(s) - 1
        while left < len(s) / 2:
            tmp = s[left]
            s[left] = s[right]
            s[right] = tmp
            left += 1
            right -= 1
        '''
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left, right = left + 1, right - 1