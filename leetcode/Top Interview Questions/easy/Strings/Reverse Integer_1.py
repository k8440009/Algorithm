class Solution:
    def reverse(self, x: int) -> int:
        MAX_INT = pow(2,31) # 2147483647
        num = ""
        if x < 0:
            tmp = str(-x)
            num += "-"
        else:
            tmp = str(x)
        for i in reversed(range(len(tmp))) :
            num += tmp[i]
        num = int(num)
        if num > MAX_INT or num < -MAX_INT - 1 :
            return 0
        else :
            return num