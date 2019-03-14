from collections import namedtuple
Mooncake = namedtuple('Mooncake', ['amount', 'sell', 'price'])

_, d = map(int, input().split())

amounts = map(float, input().split())

sells = map(float, input().split())

# (amount,sell,price)
mooncakes = (Mooncake(t[0], t[1], t[1]/t[0]) for t in zip(amounts, sells))

mooncakes = sorted(mooncakes, key=lambda m: m.price, reverse=True)

income = 0
for m in mooncakes:
    amount, sell, price = m
    if amount <= d:
        d -= amount
        income += sell
    else:
        income += d * price
        break

print("%.2f" % income)
