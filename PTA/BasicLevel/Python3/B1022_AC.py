a, b, d = map(int, input().split())

sum = a+b

rres = []
while sum != 0:
    rres.append(str(sum % d))
    sum //= d

res = ''.join(rres[::-1])

print(res if res else '0')
