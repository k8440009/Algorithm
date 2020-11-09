# 전화번호 목록
# https://programmers.co.kr/learn/courses/30/lessons/42577
def solution(phone_book):
    answer = True
    for i in range(len(phone_book)):
        for j in range(len(phone_book)):
            if i == j :
                continue
            if phone_book[i].startswith(phone_book[j]):
                answer = False
                return answer
    return answer

'''
    find, startswith
    https://dpdpwl.tistory.com/119
'''