digits = (input().split())[1:]

result = 0
for i, digit in enumerate(digits):
    for j, another in enumerate(digits):
        if i != j:
            result += int(digit + another)
print(result)
