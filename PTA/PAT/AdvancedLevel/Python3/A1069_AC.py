KAPREKAR = 6174

n = input()
_len = len(n)
if _len != 4:
    zero = '0'*(4-_len)
    n = '%s%s' % (zero, n)

while True:
    n = ''.join(sorted(n, reverse=True))
    a = int(n)
    b = int(n[::-1])
    n = a - b
    print('%04d - %04d = %04d' % (a, b, n))
    if n == KAPREKAR or n == 0:
        break
    n = str(n)
    _len = len(n)
    if _len != 4:
        zero = '0'*(4-_len)
        n = '%s%s' % (zero, n)
