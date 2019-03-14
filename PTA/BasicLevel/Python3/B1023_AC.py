digits = []
for i, cnt in enumerate(input().split()):
    for _ in range(int(cnt)):
        digits.append(i)

swap_i = 0
for i, digit in enumerate(digits):
    if digit != 0:
        swap_i = i
        break

digits[swap_i], digits[0] = digits[0], digits[swap_i]

for d in digits:
    print(d, end='')
