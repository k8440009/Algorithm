import re


def solution(dartResult):
    answer = 0
    point = {'S': 1, 'D': 2, 'T': 3}
    bonus = {'': 1, '*': 2, '#': -1}
    p = re.compile('(\d+)([SDT])([*#]?)')
    dart = p.findall(dartResult)
    for i in range(len(dart)):
        if i > 0 and dart[i][2] == '*':
            dart[i-1] *= 2
        dart[i] = int(dart[i][0]) ** point[dart[i][1]] * bonus[dart[i][2]]
    answer = sum(dart)
    return answer
