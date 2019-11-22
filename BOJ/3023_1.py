'''
    마술사 이민혁
    https://www.acmicpc.net/problem/3023
'''
R, C = map(int, input().split())
board = []
for _ in range(R):
    line = input()
    board.append(line + line[::-1])  # 대칭
A, B = map(int, input().split())
A -= 1
B -= 1

for i in range(2 * R):
    index = i
    if i >= R:
        index = 2 * R - i - 1
    if i == A:
        s = board[index]
        '''
        if s[B] == '.':
            temp = '#'
        else:
            temp = '.'
        '''
        temp = '#' if s[B] == '.' else '.'
        print(s[:B] + temp + s[B+1:])
        continue
    print(board[index])
'''
    참고
    https://blog.wonkyunglee.io/3
    파이썬 string은 불변 -> 복사해야함
    https://hashcode.co.kr/questions/6444/%ED%8C%8C%EC%9D%B4%EC%8D%AC%EC%97%90%EC%84%9C-str-object-does-not-support-item-deletion%EB%9D%BC%EB%8A%94-%EC%97%90%EB%9F%AC%EA%B0%80-%EB%82%AC%EC%8A%B5%EB%8B%88%EB%8B%A4
    https://www.acmicpc.net/source/15531193
'''
