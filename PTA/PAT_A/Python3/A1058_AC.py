class Currency:
    def __init__(self, *value):
        g, s, k = value
        self.galleon = g  # [0,10 ** 7]
        self.sickle = s  # [0,17)
        self.knut = k  # [0,29)

    def __add__(self, other):
        k = self.knut + other.knut
        if k >= 29:
            k -= 29
            s = self.sickle + other.sickle + 1
        else:
            s = self.sickle + other.sickle
        if s >= 17:
            s -= 17
            g = self.galleon + other.galleon+1
        else:
            g = self.galleon + other.galleon
        return Currency(g, s, k)

    def __str__(self):
        return '%d.%d.%d' % (self.galleon, self.sickle, self.knut)


input_ = input()

split_i = input_.find(' ')
a = map(int, input_[:split_i].split('.'))

b = map(int, input_[split_i+1:].split('.'))

print(str(Currency(*a) + Currency(*b)))
