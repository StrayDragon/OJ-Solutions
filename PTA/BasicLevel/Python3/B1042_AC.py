import string
table = {}
text = input()
for ch in text:
    if ch not in string.ascii_letters or ch == ' ':
        continue
    letter = ch.lower()
    if table.get(letter) is None:
        table[letter] = 1
    else:
        table[letter] += 1
result = sorted(table.items(), key=lambda t: t[1])
maximum = result[-1][1]
r = sorted(filter(lambda t: t[1] == maximum, result), key=lambda t: t[0])[0]
print(r[0], r[1])
