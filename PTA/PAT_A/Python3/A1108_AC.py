def is_legal(t: str) -> bool:
    def output(ok: bool) -> bool:
        if not ok:
            print('ERROR: %s is not a legal number' % t)
        return ok

    try:
        num = float(t)
    except:
        return output(False)

    if num >= -1000 and num <= 1000:
        dot_i = t.find('.')
        if dot_i != -1:
            return output(len(t)-1-dot_i <= 2)
        else:
            return output(True)
    else:
        return output(False)


_ = input()
suspicious = input().split()

numbers = list(map(float, filter(is_legal, suspicious)))

cnt = len(numbers)

if cnt >= 2:
    print('The average of %d numbers is %.2f' % (cnt, sum(numbers)/cnt))
elif cnt == 1:
    print('The average of 1 number is %.2f' % numbers[0])
else:
    print('The average of 0 numbers is Undefined')
