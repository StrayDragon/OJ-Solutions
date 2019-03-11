weight = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
z2m = {0: '1',
       1: '0',
       2: 'X',
       3: '9',
       4: '8',
       5: '7',
       6: '6',
       7: '5',
       8: '4',
       9: '3',
       10: '2', }

n = int(input())

id_nums = []
for _ in range(n):
    id_nums.append(input())


def check_it(id_num: str):
    try:
        digits = list(map(int, id_num[:-1]))
    except:
        return id_num
    checkcode = 0
    for d, w in zip(digits, weight):
        checkcode += d*w
    checkcode %= 11
    target = id_num[-1]
    if z2m[checkcode] == target:
        return None
    else:
        return id_num


result = list(filter(None, map(check_it, id_nums)))

if result:
    for _ in result:
        print(_)
else:
    print("All passed")
