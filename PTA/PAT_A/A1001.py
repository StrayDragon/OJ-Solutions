# 1001 A+B Format （20 分）
sa, sb = tuple(str(input()).split())
sum = int(sa) + int(sb)
if sum < 0:
    print('-', end='')
    sum = -sum
result = []
digits = list(str(sum))[::-1]
for i in range(len(digits)-1, -1, -1):
    print(digits[i], end='')
    if i > 0 and i % 3 == 0:
        print(',', end='')
