def solution(n, arr1, arr2):
    answer = []
    a = []
    for i in range(n):
        a.append(bin(arr1[0] | arr2[0]))

    print(a)
    for number in a:
        b = number.split('')
        # print(b)
        for i in b:
            print(i)
            temp = ''
            if i == '1':
                temp += '#'
            elif i == '0':
                temp += ' '
            # print(temp)

    return answer
