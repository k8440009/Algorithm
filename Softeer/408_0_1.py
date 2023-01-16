"""
    8단 변속기
"""
import sys
inp = sys.stdin.readline()

lines = inp.split()
result = "mixed"
if lines[0] > lines[1]:
    result = "descending"
else:
    result = "ascending"

for i in range(1, len(lines)):
    if lines[i-1] > lines[i] and result == "ascending":
        result = "mixed"
        break
    elif lines[i-1] < lines[i] and result == "descending":
        result = "mixed"
        break
print(result)