'''
    숫자고르기
    https://www.acmicpc.net/problem/2668
'''
import sys
input = sys.stdin.readline
N = int(input())
picked = []
number = [0] * (N+1)
visited = [0] * (N+1)
finished = [0] * (N+1)
for i in range(1, N+1):
    number[i] = int(input())


def dfs(current):
    cnt = 0
    visited[current] = True
    next = number[current]
    if visited[next]:
        if finished[next] == False:
            node = next
            while node != current:
                cnt += 1
                picked.append(node)
                node = number[node]
            cnt += 1
            picked.append(node)
    else:
        cnt += dfs(next)
    finished[current] = True
    return cnt


answer = 0
for i in range(1, N+1):
    if visited[i] == False:
        answer += dfs(i)
print(answer)
for num in sorted(picked):
    print(num)

'''
    참고
    9466 텀 프로젝트 (DFS, 사이클 찾기)
'''
