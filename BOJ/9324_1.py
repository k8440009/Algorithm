'''
    진짜 메세지
    https://www.acmicpc.net/problem/9324
'''
N = int(input())
for _ in range(N):
    alpha = [0 for i in range(27)]
    str = input()
    check = True
    i = 0
    while i < len(str):
        now = ord(str[i]) - ord('A')
        alpha[now] += 1
        if alpha[now] == 3:
            if i == len(str)-1 or str[i] != str[i+1]:
                check = False
                break
            else:
                alpha[now] = 0
                i += 1
        i += 1
    if check:
        print("OK")
    else:
        print("FAKE")
