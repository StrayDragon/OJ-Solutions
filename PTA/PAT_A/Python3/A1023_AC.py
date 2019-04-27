integer = input()
doubled = str(int(integer) * 2)

table = [0 for _ in range(10)]
for digit in integer:
    table[int(digit)] += 1

for digit in doubled:
    table[int(digit)] -= 1

is_only_permutation = True
for cnt in table:
    if cnt != 0:
        is_only_permutation = False
        break

print("Yes" if is_only_permutation else "No")
print(doubled)
