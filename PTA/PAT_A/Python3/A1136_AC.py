digits = input()


def is_palindromic(digits: str) -> bool:
    if digits[::-1] == digits:
        return True
    else:
        return False


got_it = False
for _ in range(10):
    if is_palindromic(digits):
        print("%s is a palindromic number." % digits)
        got_it = True
        break
    rdigits = digits[::-1]
    result = int(digits) + int(rdigits)
    print('%s + %s = %d' % (digits, rdigits, result))
    digits = str(result)

if not got_it:
    print('Not found in 10 iterations.')
