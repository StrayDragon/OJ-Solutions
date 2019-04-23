import sys

_ = input()

lines = []
for line in sys.stdin:
    lines.append(line[len(line)-2::-1])

min_len = len(min(lines))
result, is_first = "", True
j = 0
while j < min_len:
    ch, is_same = lines[0][j], True
    for i in range(len(lines)):
        if lines[i][j] != ch:
            is_same = False
    if is_first and not is_same:
        is_first = False
        break

    if is_same:
        result += ch
    else:
        break
    j += 1

if j != 0:
    print(result[::-1])
else:
    print('nai')
