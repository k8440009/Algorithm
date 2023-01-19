"""
    longest-palindromic-substring
    풀이 1 : 중앙을 중심으로 확장하는 풀이
"""
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(left: int, right: int) -> str:
            # print("bf left={0}, right={1}".format(left, right))
            # print("bf_str={0}".format(s[left:right]))
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            # print("af left={0}, right={1}".format(left, right))
            # print("af_str={0}".format(s[left + 1:right]))
            return s[left + 1:right]

        # 해당 사항이 없는 경우
        # 길이 1, 일반 문자열과 뒤집은 결과가 같은 경우
        if len(s) < 2 or s == s[::-1]:
            return s
        result = ''
        # 슬라이등 윈도우 우측으로 이동
        for i in range(len(s) - 1):
            result = max(result,
                         expand(i, i + 1),
                         expand(i, i + 2),
                         key=len)
        return result


a = Solution()
s = "babad"
print(a.longestPalindrome(s))
