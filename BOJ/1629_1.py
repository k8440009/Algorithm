'''
    곱셈 
    https://www.acmicpc.net/problem/1629
'''
from sys import stdin

input = stdin.readline


def multiply(a, b, c):
    if b == 1:
        return a
    if b % 2 == 0:  # 짝수 => 절반 * 절반
        half = multiply(a, b//2, c) % c
        return half * half % c
    else:  # 홀수 => n-1 * 1
        return multiply(a, b-1, c) * a % c


A, B, C = map(int, input().split())
print(multiply(A, B, C) % C)
