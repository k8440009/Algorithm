import re
from collections import Counter


def solution(str1, str2):
    answer = 0

    list1 = []
    list2 = []

    p = re.compile('[a-zA-Z]+')

    for i in range(len(str1)-1):
        m1 = p.match(str1[i].upper())
        m2 = p.match(str1[i+1].upper())

        if m1 and m2:
            list1.append(str(m1.group()+m2.group()))

    for i in range(len(str2)-1):
        m1 = p.match(str2[i].upper())
        m2 = p.match(str2[i+1].upper())

        if m1 and m2:
            list2.append(str(m1.group()+m2.group()))

    m1 = Counter(list1)
    m2 = Counter(list2)

    inter = list((m1 & m2).elements())
    union = list((m1 | m2).elements())

    if len(union) == 0:
        answer = 65536
    else:
        answer = int(len(inter) / len(union) * 65536)

    return answer
