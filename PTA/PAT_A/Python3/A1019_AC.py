n, b = map(int, input().split())


def convert(n: int, b: int) -> list:
    s = []
    while n != 0:
        s.append(n % b)
        n //= b
    else:
        if len(s) == 0:
            s.append(0)
    return s[::-1]


s = convert(n, b)

if s == s[::-1]:
    print("Yes")
else:
    print("No")

if len(s) != 0:
    print(s[0], end='')
for bit in s[1:]:
    print(" %d" % bit, end='')
