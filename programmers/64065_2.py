# 튜플
# https://programmers.co.kr/learn/courses/30/lessons/64065
def solution(s):
    answer, data =[], []
    index = 1
    while index < len(s):
        if s[index] == '{':
            tmp = []
            num = ""
            while True:
                if s[index] == '}':
                    tmp.append(int(num))
                    break
                if s[index] >= '0' and s[index] <= '9':
                    num += s[index]
                elif s[index] == ',':
                    tmp.append(int(num))
                    num = ""
                index += 1
            data.append(tmp)
        index += 1
    lst = sorted(data, key=lambda x: len(x))
    for data in lst:
        tmp = list(set(data) - set(answer))
        for d in tmp:
            answer.append(d)
    return answer

#solution("{{123}}")
#solution("{{20,111},{111}}")
# solution("{{2},{2,1},{2,1,3},{2,1,3,4}}")
# solution("{{1,2,3},{2,1},{1,2,4,3},{2}}")