'''
    영수증
    https://www.acmicpc.net/problem/5565
'''

total = int(input())
for i in range(0, 9):
    total -= int(input())
print(total)
