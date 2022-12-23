"""
    중복 문자 없는 가장 긴 부분 문자열

    슬라이딩 윈도우와 투 포인터로 사이즈 조절

    1. 포인터 2개는 왼쪽에서 출발한다.
    왼쪽 포인터 : start
    오른쪽 포인터 : index 변수

    2. for 문
    2_1) used 존재
    - start를 used[char] + 1로 갱신한다.
    2_2) used 미존재
    - 매번 max로 부분 문자열 길이를 확인하면서 더 큰 값인 경우 갱신

"""
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        used = {}
        max_length = start = 0

        for index, char in enumerate(s):
            # 이미 등장 했던 문자라면 'start' 위치 갱신
            if char in used and start <= used[char]:
                start = used[char] + 1
            else : # 최대 부분 문자열 길이 갱신
                max_length = max(max_length, index - start + 1)
            # 현재 문자의 위치 삽입
            used[char] = index

        return max_length

a = Solution()
print(a.lengthOfLongestSubstring("abcabcbb"))