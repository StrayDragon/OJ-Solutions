def deal_with_B(digit: int):
    print('B'*digit, end='')


def deal_with_S(digit: int):
    print('S'*digit, end='')


def deal_with_n(digit: int):
    for i in range(1, digit+1):
        print(str(i), end='')


digits = list(map(lambda x: int(x), input()))

length = len(digits)
if length == 3:
    deal_with_B(digits[0])
    deal_with_S(digits[1])
    deal_with_n(digits[2])
elif length == 2:
    deal_with_S(digits[0])
    deal_with_n(digits[1])
elif length == 1:
    deal_with_n(digits[0])
