# 불량 사용자
# https://programmers.co.kr/learn/courses/30/lessons/64064

selected = [0 for _ in range(9)]
answer = 0
total_data = []
def solve(node, user_id, banned_id):
    users = []
    for i in node:
        users.append(user_id[i])
    for i in range(len(banned_id)):
        index = 0
        user, ban = users[i], banned_id[i]
        if len(ban) != len(user) :
            return
        while (index < len(ban)):
            if user[index] != ban[index] and ban[index] != '*':
                return
            index += 1
    data = sorted(users)
    if(total_data.count(data) == 0):
        total_data.append(data)

def dfs(cnt, node, size, user_id, banned_id):
    if(cnt == size):
        solve(node, user_id, banned_id)
        return
    
    for i in range(len(user_id)):
        if selected[i] == 1:
            continue
        node.append(i)
        selected[i] = 1
        dfs(cnt + 1, node, size, user_id, banned_id)
        node.pop()
        selected[i] = 0

def solution(user_id, banned_id):
    answer = 0
    node = []
    dfs(0, node, len(banned_id), user_id, banned_id)
    answer = len(total_data)
    #print(answer)
    #print(total_data)
    return answer

#solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "abc1**"])
#solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["*rodo", "*rodo", "******"])
#solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["fr*d*", "*rodo", "******", "******"])
