'''
    서버
    https://www.acmicpc.net/problem/10409
'''
N, T = map(int, input().split())
work = list(map(int, input().split()))
total = 0
cnt = 0
for i in range(len(work)):
    total += work[i]
    if(total > T):
        break
    cnt += 1
print(cnt)

'''
    참고
    https://dojang.io/mod/page/view.php?id=2179

    m=lambda:map(int,input().split())
    _,t=m()
    s=0
    j=0
    for i in m():
        if s+i>t:break
        j+=1;s+=i
    print(j)
'''
