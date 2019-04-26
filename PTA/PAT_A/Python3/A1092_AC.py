shop_beads, needed_beads = list(input()), list(input())

shop: dict = {}
for bead in shop_beads:
    if bead not in shop:
        shop[bead] = 1
    else:
        shop[bead] += 1

need_buy, not_found_cnt = True, 0
for bead in needed_beads:
    if bead in shop:
        if shop[bead] != 0:
            shop[bead] -= 1
        else:
            need_buy = False
            not_found_cnt += 1
    else:
        need_buy = False
        not_found_cnt += 1

if need_buy:
    print('Yes', len(shop_beads) - len(needed_beads))
else:
    print('No', not_found_cnt)
