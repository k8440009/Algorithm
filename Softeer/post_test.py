import sys

line = sys.stdin.readline()
words = line.split('-')
result = ""

for word in words:
    result += word[0].upper()

print(result)