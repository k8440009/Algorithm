# Sorting: Bubble Sort
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countSwaps function below.


def countSwaps(a):
    cnt = 0
    n = len(a)
    i = 0
    while i < n:
        for j in range(n - 1):
            if a[j] > a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]
                cnt += 1
        i += 1

    print("Array is sorted in {} swaps.".format(cnt))
    print("First Element: {}".format(a[0]))
    print("Last Element: {}".format(a[n-1]))


if __name__ == '__main__':
    n = int(input())

    a = list(map(int, input().rstrip().split()))

    countSwaps(a)
