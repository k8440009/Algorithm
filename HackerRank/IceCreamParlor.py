# Hash Tables: Ice Cream Parlor
#!/bin/python3

import math
import os
import random
import re
import sys
import collections

# Complete the whatFlavors function below.


def whatFlavors(cost, money):
    product = {}
    firstIndex = 0
    secondIndex = 0
    for i in range(len(cost)):
        secondIndex = i
        '''
            유용한 메서드
            dictionary.get(key) => 특정값 리턴
            1) value
            2) None
            3) 에러

            멤버쉽연산자 in 사용 
            if key in dictionary
        '''
        if money - cost[i] in product:
            firstIndex = product.get(money - cost[i])
            print("{} {}".format(firstIndex + 1, secondIndex + 1))
        product[cost[i]] = secondIndex


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        money = int(input())

        n = int(input())

        cost = list(map(int, input().rstrip().split()))

        whatFlavors(cost, money)
