'''
    회문
    https://www.acmicpc.net/problem/17609
'''
import sys
for _ in range(int(sys.stdin.readline())):
    s = sys.stdin.readline().strip()
    # 문자열 앞과, 문자열 뒤를 한개씩 비교
    if s == s[::-1]:
        print(0)
    else:
        index = 0
        # 일치하지 않는 곳의 index를 찾는다.
        while s[index] == s[-index-1]:
            index += 1
        # 앞으로 한 칸 이동한 문자열
        u = s[index + 1: len(s) - index]
        # 뒤에서 한 칸 이동한 문자열
        v = s[index: -index - 1]
        print(1 if u == u[::-1] or v == v[::-1] else 2)
