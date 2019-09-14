def solution(phone_number):
    '''
    answer = ''
    size = len(phone_number) - 4

    index = 0
    while index < size:
        answer += '*'
        index += 1

    for num in phone_number[size:]:
        answer += num

    return answer

    '''

    return "*"*(len(phone_number)-4) + phone_number[-4:]
