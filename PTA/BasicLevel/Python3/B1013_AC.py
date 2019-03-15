def gen_primes():
    """https://stackoverflow.com/a/568618"""
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


m, n = map(int, input().split())
cnt = 1
for i, prime in enumerate(gen_primes()):
    if m-1 <= i and i < n:
        if cnt % 10 == 0 or i == n-1:
            print(prime)
        else:
            print(prime, '', end='')
        cnt += 1
    if i > n + 1:
        break

# https://stackoverflow.com/a/33951990
# import re
# def isprime(n):
#     return re.compile(r'^1?$|^(11+)\1+$').match('1' * n) is None


# prime_nums = [x for x in range(10000) if isprime(x)]

# m, n = map(int, input().split())

# cnt = 1
# for i in range(m-1, n):
#     if cnt % 10 == 0:
#         print()
#     else:
#         print(prime_nums[i], end='')
#     cnt += 1
