'''
    상근날드
    https://www.acmicpc.net/problem/5543
'''

minBuger = 987654321
minDrink = 987654321
for i in range(0, 5):
    if i < 3:
        temp = int(input())
        minBuger = min(minBuger, temp)
    else:
        temp = int(input())
        minDrink = min(minDrink, temp)

print(minBuger + minDrink - 50)
