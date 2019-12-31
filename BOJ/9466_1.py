'''
    텀 프로젝트 DFS, 사이클찾기
    https://www.acmicpc.net/problem/9466
'''
import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)


def dfs(current):
    cnt = 0
    visited[current] = True
    next = people[current]
    if visited[next]:
        if finished[next] == False:
            node = next
            while node != current:
                cnt += 1
                node = people[node]
            cnt += 1
    else:
        cnt += dfs(next)
    finished[current] = True
    return cnt


for _ in range(int(input())):
    N = int(input())
    visited = [0] * (N+1)
    finished = [0] * (N+1)
    people = [0] * (N+1)
    temp = list(map(int, input().split()))
    for i in range(N):
        people[i+1] = temp[i]
    answer = 0
    for i in range(1, N+1):
        if visited[i] == False:
            answer += dfs(i)
    print(N - answer)
