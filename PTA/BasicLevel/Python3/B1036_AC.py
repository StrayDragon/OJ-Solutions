column, ch = input().split()
column = int(column)

row = column//2 + 1 if abs(column / 2 - column // 2) >= 0.5 else column//2
for r in range(row):
    if r == 0 or r == row-1:
        print(ch*column)
    else:
        print(ch, end='')
        print(' '*(column-2), end='')
        print(ch)
