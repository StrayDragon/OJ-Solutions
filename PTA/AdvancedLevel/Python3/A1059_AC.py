def gen_primes():
    d = {}
    q = 2
    while True:
        if q not in d:
            yield q
            d[q*q] = [q]
        else:
            for p in d[q]:
                d.setdefault(p+q, []).append(p)
            del d[q]
        q += 1


primes = []
for i, p in enumerate(gen_primes()):
    primes.append(p)
    if i > 100010:
        break


class Factor(object):
    def __init__(self, x, c):
        self.x = x
        self.cnt = c


factors = [Factor(0, 0) for _ in range(10)]


n = int(input())

num = 0
if n == 1:
    print('1=1', end='')
else:
    print('%d=' % n, end='')
    from math import sqrt
    sqr = int(sqrt(n))
    for i, prime in enumerate(primes):
        if prime > sqr:
            break
        if n % prime == 0:
            factors[num].x = prime
            while(n % prime == 0):
                factors[num].cnt += 1
                n //= prime
            num += 1
        if n == 1:
            break
    if n != 1:
        factors[num].x = n
        factors[num].cnt = 1
        num += 1
    for i in range(num):
        if i > 0:
            print('*', end='')
        print(factors[i].x, end='')
        if factors[i].cnt > 1:
            print('^%d' % factors[i].cnt, end='')
