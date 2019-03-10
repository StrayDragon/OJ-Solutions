CLK_TCK = 100

c1, c2 = tuple(map(int, input().split()))

seconds = (c2 - c1) / CLK_TCK

m, s = divmod(seconds, 60)
h, m = divmod(m, 60)


def estimate_it(x): return int(x) + 1 if x - int(x) >= 0.5 else int(x)


print("%02d:%02d:%02d" % (h, m, estimate_it(s)))
