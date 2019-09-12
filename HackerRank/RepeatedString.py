# Repeated String
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.

'''
s = input().strip()
n = int(input().strip())
L = len(s)
print(s.count('a') * (n//L) + s[:n % L].count('a'))
'''


def repeatedString(s, n):
    aCnt = s.count('a')
    cnt = aCnt * (n // len(s))
    '''
    for i in range(n % len(s)):
        if s[i] == 'a':
            cnt += 1
    '''
    cnt += s[:n % len(s)].count('a')
    return cnt


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
