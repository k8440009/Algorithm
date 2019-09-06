#!/bin/python3

import math
import os
import random
import re
import sys
import collections

# Complete the makeAnagram function below.


def makeAnagram(a, b):
    a = collections.Counter(a)
    b = collections.Counter(b)

    c = a - b
    d = b - a
    e = c + d

    return len(list(e.elements()))


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = input()

    b = input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
