polynomial = {}

import math
import sys
for line in sys.stdin:
    # 处理输入
    poly = line.split()
    # 算法逻辑
    k = poly[0]
    if k == 0:
        exit()
    nlist = poly[1::2]
    anlist = poly[2::2]
    for k, v in zip(nlist, anlist):
        if polynomial.get(k) is None:
            # 此时还没有此元素
            polynomial[k] = float(v)
        else:
            polynomial[k] += float(v)
        # if math.isclose(polynomial[k], 0):
        #     del polynomial[k]

result_list = [(k, polynomial[k]) for k in sorted(
    polynomial.keys(), reverse=True)]

# 处理输出
result = []
for e1, e2 in result_list:
    if math.isclose(e2, 0):
        continue
    result.append(" %s %0.1f" % (e1, e2))
result.insert(0, str(len(result)))
print(''.join(result))
