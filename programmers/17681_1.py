# 비밀지도
# https://programmers.co.kr/learn/courses/30/lessons/17681
def solution(n, arr1, arr2):
    answer = []
    for i, j in zip(arr1, arr2):
        a = str(bin(i | j)[2:])
        a = a.rjust(n ,'0')
        a = a.replace('1', '#')
        a = a.replace('0', ' ')
        answer.append(a)
    return answer