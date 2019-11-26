'''
    올림픽
    https://www.acmicpc.net/problem/8979
'''
N, K = map(int, input().split())
nation = [0] * N
for i in range(N):
    nation[i] = list(map(int, input().split()))
nation.sort(key=lambda medal: (-medal[1], -medal[2], -medal[3]))  # 내림 차순 정렬
idx = [nation[i][0] for i in range(N)].index(K)  # K의 index를 찾는다.
while nation[idx-1][1:] == nation[idx][1:]:  # 메달 수가 같으면 감소
    idx -= 1
print(idx + 1)


'''
    참고
    https://wayhome25.github.io/python/2017/03/07/key-function/
    https://home-body.tistory.com/216
'''
