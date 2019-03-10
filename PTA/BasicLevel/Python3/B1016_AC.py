a, da, b, db = input().split()

try:
    pa = int(''.join(list(_ for _ in a if _ == da)))
except:
    pa = 0

try:
    pb = int(''.join(list(_ for _ in b if _ == db)))
except:
    pb = 0

print(pa+pb)
