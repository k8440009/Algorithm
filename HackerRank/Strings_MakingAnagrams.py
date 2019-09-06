#!/bin/python3

import math
import os
import random
import re
import sys
import collections

# Complete the makeAnagram function below.


def makeAnagram(a, b):

    dict1 = collections.Counter(a)
    dict2 = collections.Counter(b)

    key1 = dict1.keys()
    key2 = dict2.keys()

    count1 = len(key1)
    count2 = len(key2)

    set1 = set(key1)
    commonKeys = len(set1.intersection(key2))

    if (commonKeys == 0):
        return count1 + count2
    else:
        return (max(count1, count2)-commonKeys)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = input()

    b = input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
