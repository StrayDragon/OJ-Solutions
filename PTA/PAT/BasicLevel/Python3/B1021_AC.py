digits = input()

mapping = {}

for digit in digits:
    if not mapping.get(digit):
        mapping[digit] = 1
    else:
        mapping[digit] += 1

result = sorted(mapping.items())

for k, v in result:
    print("%s:%d" % (k, v))
