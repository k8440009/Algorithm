'''
    분해합
    https://www.acmicpc.net/problem/2231
'''


def recursive(n):
    start = max(n - 9 * len(str(n)), 0)
    for i in range(start, n):
        li = list(map(int, str(i)))
        if sum(li, i) == n:
            return i
    return 0


print(recursive(int(input())))
