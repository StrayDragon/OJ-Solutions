def collatz(number):
    cnt = 0
    while number != 1:
        if number % 2 == 0:
            number = number // 2
            cnt += 1
        elif number % 2 == 1:
            number = number*3 + 1
    return cnt


print(collatz(int(input())))
