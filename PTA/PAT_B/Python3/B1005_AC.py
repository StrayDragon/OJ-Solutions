def cached_collatz(k) -> list:
    cached = []
    while k != 1:
        if k % 2 == 0:
            k //= 2
        else:
            k = (k*3 + 1) // 2
        cached.append(k)
    return cached


_ = input()
nums = list(map(lambda s: int(s), input().split()))

key_nums_set = set()
for num in nums:
    key_nums = cached_collatz(num)
    for kn in key_nums:
        key_nums_set.add(kn)
result = []
for num in nums:
    if num not in key_nums_set:
        result.append(num)
result.sort(reverse=True)

if result:
    print(result[0], end='')
for n in result[1:]:
    print(" " + str(n), end='')
