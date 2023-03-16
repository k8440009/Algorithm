"""
    중복 문자 없는 가장 긴 부분 문자열
    https://leetcode.com/problems/longest-substring-without-repeating-characters/

    슬라이딩 윈도우와 투 포인터
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        used = {}
        max_length = start = 0

        for index, char in enumerate(s):
            """
                1. 이미 등장했던 문자라면 'start' 위치 갱신
                2. 무작정 start를 변경하면 안되고, 
                슬라이딩 윈도우의 바깥에 있는 문자만 옮긴다.
            """
            if char in used and start <= used[char]:
                # print("start={0}, used[char]={1}".format(start, used))
                start = used[char] + 1
            else:  # 최대 부분 문자열 길이 갱신
                # print("index={0}, start={1}".format(index, start))
                max_length = max(max_length, index - start + 1)

            # 현재 문자의 위치 삽입
            used[char] = index

        return max_length
