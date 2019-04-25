from string import digits, ascii_letters


def in_range(target, s, e) -> bool:
    return ord(s) <= ord(target) and ord(target) <= ord(e)


records = []
first_collected = False
for i, t in enumerate(zip(input(), input())):
    if first_collected and t[0] == t[1] and (in_range(t[0], 'A', 'N') or t[0] in digits):
        records.append((i, t[0]))
        break
    if not first_collected and t[0] == t[1] and in_range(t[0], 'A', 'G'):
        records.append((i, t[0]))
        first_collected = True

for i, t in enumerate(zip(input(), input())):
    if t[0] == t[1] and t[0] in ascii_letters:
        records.append((i, t[0]))
        break

capital2week = {'A': 'MON', 'B': 'TUE', 'C': 'WED',
                'D': 'THU', 'E': 'FRI', 'F': 'SAT', 'G': 'SUN'}


def char2hour(ch: str) -> int:
    return int(ch) if ord(ch) <= ord('9') \
        else ord(ch)-ord('A') + 10


print("%s %02d:%02d" %
      (capital2week[records[0][1]],
          char2hour(records[1][1]),
          records[2][0]))
