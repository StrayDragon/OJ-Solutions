m, n, k = tuple(map(int, input().split()))

for _ in range(k):
    stk = []
    nums = list(map(int, input().split()))

    is_invalid = False
    cur = 0

    for i in range(1, n+1):
        stk.append(i)
        if len(stk) > m:
            is_invalid = True
            break

        while len(stk) != 0 and stk[-1] == nums[cur]:
            stk.pop()
            cur += 1

    if len(stk) != 0 or is_invalid:
        print("NO")
    else:
        print("YES")
