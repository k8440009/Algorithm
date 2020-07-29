# 비밀지도
# https://programmers.co.kr/learn/courses/30/lessons/17681
def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        new_str = str (bin(arr1[i] | arr2[i])[2:])
        print(new_str)
        new_str = new_str.rjust(n, '0')
        print(new_str)
        print("\n")
        new_str = new_str.replace('1', '#')
        new_str = new_str.replace('0', ' ')
        answer.append(new_str)
    return answer