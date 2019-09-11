def solution(n, arr1, arr2):
    answer = []
    for i, j in zip(arr1, arr2):
        a = str(bin(i | j)[2:])
        # 파이썬의 bin은 빈 공간을 0으로 채우지 않기 때문에 rjust를 사용하여 빈 공간을 0으로 채운다
        a = a.rjust(n, '0')
        a = a.replace('1', '#')
        a = a.replace('0', ' ')
        answer.append(a)
    return answer
