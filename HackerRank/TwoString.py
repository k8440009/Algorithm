# Two Strings
#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter

# Complete the twoStrings function below.


def twoStrings(s1, s2):
    p = re.compile('[a-z]')
    m1 = Counter(p.findall(s1))
    m2 = Counter(p.findall(s2))

    # len(list(m1&m2)) : list 크기가 없으면 NONE 리턴
    if(len(list(m1 & m2))) >= 1:
        return "YES"
    else:
        return "NO"


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s1 = input()

        s2 = input()

        result = twoStrings(s1, s2)

        fptr.write(result + '\n')

    fptr.close()
