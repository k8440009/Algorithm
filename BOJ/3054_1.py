'''
    피터팬 프레임
    https://www.acmicpc.net/problem/3054
'''
n = input()  # import sys n = sys.stdin.readline().strip('\n')
m = len(n)
one = '.' + '.#...#...*..'*(m//3) + '.#..'*(m % 3)
two = '.' + '#.#.#.#.*.*.'*(m//3) + '#.#.'*(m % 3)
three = '#'

for i in range(m):
    if(i+1) % 3 == 0:
        three = three[0:-1]+'*.' + n[i] + '.*'
    else:
        three += '.' + n[i] + '.#'

for i in (one, two, three, two, one):
    print(i)
