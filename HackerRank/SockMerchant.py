#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict

# Complete the sockMerchant function below.


def sockMerchant(n, ar):
    ar.sort()

    d = defaultdict(int)

    for k in ar:
        d[k] += 1

    for num in d.values():
        cnt += num//2

    return cnt


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
