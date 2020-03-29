# 파이썬 시간 표현

answer = 540
div, mod = divmod(540, 60)
# print(div, mod)
# 지정자를 사용하여 시간
print("%02d:%02d" % (div, mod))
# print("%02d:%02d", 540)
