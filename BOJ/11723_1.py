'''
    집합
    https://www.acmicpc.net/problem/11723
'''
import sys
M = int(sys.stdin.readline())
i = 0
total = 0
while i < M:
    str = sys.stdin.readline()
    cmd = str.split(" ")[0]

    if cmd == "all\n":
        total = (1 << 21) - 1
    elif cmd == "empty\n":
        total = 0
    else:
        x = int(str.split(" ")[1])
        if cmd == "add":
            total |= (1 << x)
        elif cmd == "remove":
            total &= ~(1 << x)
        elif cmd == "check":
            result = total & (1 << x)
            if result:
                print(1)
            else:
                print(0)
        elif cmd == "toggle":
            total ^= (1 << x)
    i += 1


'''
    참고
    Python sys.stdin과 sys.stdin.readline()
    https://bnzn2426.tistory.com/105
    https://www.acmicpc.net/board/view/855
    https://demoversion.tistory.com/37
    https://home-body.tistory.com/553
'''
