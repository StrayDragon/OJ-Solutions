MAXN = 1000

n = int(input())

keys = map(int, input().split())

sorted_keys = sorted(keys)

i = 0
cbt_nodevars = [None for _ in range(MAXN+10)]


def in_order(root):
    global i
    if(root > n):
        return
    in_order(root * 2)
    cbt_nodevars[root] = sorted_keys[i]
    i += 1
    in_order(root * 2 + 1)


in_order(1)

print(cbt_nodevars[1], end='')
for nodevar in cbt_nodevars[2:n+1]:
    print('', nodevar, end='')
