t = int(input())
for _ in range(t):
    a, b, c = tuple(map(int, input().split()))
    print("Case #%d: %s" % (_+1, 'true' if a + b > c else 'false'))
