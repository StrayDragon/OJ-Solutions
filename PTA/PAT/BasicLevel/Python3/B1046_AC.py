n = int(input())

cnt1, cnt2 = 0, 0
for _ in range(n):
    guess1, actual1, guess2, actual2 = tuple(map(int, input().split()))
    expected = guess1 + guess2
    if actual1 == expected and actual2 != expected:
        cnt2 += 1
    elif actual1 != expected and actual2 == expected:
        cnt1 += 1

print(cnt1, cnt2)
