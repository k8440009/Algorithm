#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.


def countingValleys(n, s):
    cnt = 0
    height = 0  # 현재 높이
    seaLevel = 0

    for now in s:
        preHeight = height
        if now == 'U':
            height += 1
        elif now == 'D':
            height -= 1

        if height == seaLevel and preHeight < 0:
            cnt += 1

    return cnt


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
