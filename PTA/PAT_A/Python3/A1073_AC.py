from typing import List

s = input()
base_symbol = s[0]
e_pos = 0
for i in range(1, len(s)):
    if s[i] == 'E':
        e_pos = i
        break
base: str = s[1:e_pos]
power_symbol = s[e_pos+1]
power = s[e_pos+2:]
dot_pos = 0
for i in range(len(base)):
    if base[i] == '.':
        dot_pos = i

if power_symbol == '-':
    base = '0'*int(power) + base

nbase = [c for c in base if c != '.']

if power_symbol == '-':
    nbase.insert(1, '.')
else:
    if dot_pos+int(power) >= len(nbase):
        nbase.extend('0'*(dot_pos+int(power)-len(nbase)))
    else:
        nbase.insert(dot_pos+int(power), '.')

if base_symbol == '-':
    nbase.insert(0, '-')
print(''.join(nbase))
