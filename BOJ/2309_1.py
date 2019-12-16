'''
    일곱 난쟁이
    https://www.acmicpc.net/problem/2309
'''
import sys
dwarf = []
total = 0
for _ in range(9):
    height = int(sys.stdin.readline())
    total += height
    dwarf.append(height)

dwarf.sort()

for i in range(9):
    for j in range(i + 1, 9):
        if total - dwarf[i] - dwarf[j] == 100:
            for k in range(9):
                if k != i and k != j:
                    print(dwarf[k])
            sys.exit(0)
