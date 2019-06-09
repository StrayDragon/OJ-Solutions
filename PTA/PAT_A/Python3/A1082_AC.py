# reference: https://gumble.pw/python-num2chinese.html


import itertools


def revuniq(l):
    return ''.join(
        k + ' ' for k, g in itertools.groupby(reversed(l))
    )


def digits2pinyin(digits):
    basic = ('ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu')
    unit1 = ('Shi', 'Bai', 'Qian')
    unit2 = ('Wan', 'Yi')
    result = []
    nd = str(digits)
    if nd[0] == '-':
        result.append('Fu')
    integer = nd.lstrip('+-')
    if int(integer):
        splitted = [integer[max(i - 4, 0):i]
                    for i in range(len(integer), 0, -4)]
        intresult = []
        for nu, unit in enumerate(splitted):
            if int(unit) == 0:  # 0000
                intresult.append(basic[0])
                continue
            ulist = []
            unit = unit.zfill(4)
            for nc, ch in enumerate(reversed(unit)):
                if ch == '0':
                    if ulist:  # ???0
                        ulist.append(basic[0])
                elif nc == 0:
                    ulist.append(basic[int(ch)])
                elif nc == 1 and ch == '1' and unit[1] == '0':
                    ulist.append(unit1[0])
                else:
                    ulist.append(basic[int(ch)] + ' ' + unit1[nc - 1])
            ustr = revuniq(ulist)
            if nu == 0:
                intresult.append(ustr)
            else:
                intresult.append(ustr + unit2[nu - 1])
        result.append(revuniq(intresult).strip(basic[0]))
    else:
        result.append(basic[0])
    return result


res = digits2pinyin(input())
print(''.join(res).strip())
