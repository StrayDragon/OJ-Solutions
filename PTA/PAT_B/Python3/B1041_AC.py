n = int(input())

infos_table = {}
for _ in range(n):
    zkzh, sj, ks = tuple(map(int, input().split()))
    infos_table[sj] = (zkzh, ks)

m = int(input())

seats = [int(x) for x in input().split()]

for seat in seats:
    info = infos_table[seat]
    print(info[0], info[1])
