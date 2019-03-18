def retrieve_component(components):
    bucket = []
    _ = ''
    can_collect = False
    for it in components:
        if it == '[':
            can_collect = True
            continue
        elif it == ']':
            can_collect = False
        if can_collect:
            _ += it
        else:
            if _ != '':
                bucket.append(_)
            _ = ''
    return bucket


hands = retrieve_component(input())
eyes = retrieve_component(input())
mouths = retrieve_component(input())
k = int(input())
for _ in range(k):
    h1, e1, m, e2, h2 = map(lambda e: int(e)-1, input().split())
    if h1 >= len(hands) or h1 >= len(hands) or e1 >= len(eyes) or e2 >= len(eyes) or m >= len(mouths):
        print(r'Are you kidding me? @\/@')
    else:
        print("%s(%s%s%s)%s" %
              (hands[h1], eyes[e1], mouths[m], eyes[e2], hands[h2]))
