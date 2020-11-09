# 스킬트리
# https://programmers.co.kr/learn/courses/30/lessons/49993
def is_set(c, set):
    for ch in set:
        if (ch == c):
            return 1
    return 0

def solution(skill, skill_trees):
    answer = 0
    skill_list = list(skill)
    for data in skill_trees:
        arr = []
        flag = True
        # for alpha in range(len(data)):
        for alpha in data:
            if is_set(alpha, skill_list) == 1:
                arr.append(alpha)
        for i in range(len(arr)):
            if arr[i] != skill_list[i]:
                flag = False
                break
        if flag:
            answer += 1
    return answer