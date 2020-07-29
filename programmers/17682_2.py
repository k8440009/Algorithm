# 다트 게임
# https://programmers.co.kr/learn/courses/30/lessons/17682
def solution(dartResult):
    point = []
    num = ""
    for data in dartResult :
        if data >= '0' and data <= '9' :
            num += data
        else :
            if data == 'S' :
                point.append(int(num) ** 1)
                num = ""
            elif data == 'D' :
                point.append(int(num) ** 2)
                num = ""
            elif data == 'T' :
                point.append(int(num) ** 3)
                num = ""
            elif data == '*' :
                    if len(point) > 1:
                        point[-2] *= 2
                    point[-1] *= 2
            elif data == '#' :
                point[-1] *= -1
    return sum (point)

'''
    참고 자료
    https://hongseongsu.github.io/python/algorism/2018/09/02/2017%EC%B9%B4%EC%B9%B4%EC%98%A4-%EB%B8%94%EB%9D%BC%EC%9D%B8%EB%93%9C-%ED%85%8C%EC%8A%A4%ED%8A%B8-1%EC%B0%A8-%EB%8B%A4%ED%8A%B8%EA%B2%8C%EC%9E%84.html
'''