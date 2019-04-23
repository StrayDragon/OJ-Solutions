NOT_FOUND = -1
s1: str = input()
s2: str = input()

result = ""
for c in s1:
    if s2.find(c) == NOT_FOUND and result.find(c.upper()) == NOT_FOUND:
        result += c.upper()

print(result)
