'''
    수리공 항승
    https://www.acmicpc.net/problem/1449
'''
import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
MAX = 1000 + 1
N, L = map(int, input().split())
tape = [0] * MAX
pipe = list(map(int, input().split()))
pipe.sort()


def solve():
    cnt = 0
    for pos in pipe:
        if tape[pos] == False:
            # 누수된 곳에 길이가 L인 테이프를 붙인다.
            for i in range(pos, pos + L):  # 인덱스 초과주의
                if i < MAX:
                    tape[i] = True
                else:
                    break
    # 테이프를 모두 붙인 후 테이프 갯수를 센다.
    i = 1
    while i < MAX:
        if tape[i]:
            cnt += 1
            i += (L-1)
        i += 1
    return cnt


print(solve())
