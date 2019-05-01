import math
n = int(input())

for _ in range(n):
    z = input()
    mid = len(z) // 2
    a, b, not_zero = int(z[:mid]), int(z[mid:]), True
    if a * b == 0:
        not_zero = False
        result = 0
    else:
        result = int(z) / (a*b)
    if not_zero and math.isclose(result, int(result)):
        print('Yes')
    else:
        print('No')
