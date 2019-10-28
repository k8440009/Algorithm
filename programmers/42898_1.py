'''
    등굣길
    https://programmers.co.kr/learn/courses/30/lessons/42898
'''

MOD = 1000000007


def solution(m, n, puddles):
    dp = [[0] * (m + 1) for i in range(n + 1)]
    dp[1][0] = 1
    for y in range(1, n+1):
        for x in range(1, m + 1):
            if [x, y] in puddles:
                dp[y][x] = 0
            else:
                dp[y][x] = (dp[y-1][x] + dp[y][x-1]) % MOD
    return dp[n][m]


'''
    참고
    https://codedrive.tistory.com/57
'''
