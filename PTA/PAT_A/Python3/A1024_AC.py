n, k = map(int, input().split())


def not_palindromic(num: str):
    return num != num[::-1]


i = 0
while not_palindromic(str(n)) and i < k:
    n += int(str(n)[::-1])
    i += 1

print(n)
print(i)
