import sys
polynomial = {}

for line in sys.stdin:
    # 处理输入
    poly = line.split()
    elist = poly[1::2]
    clist = poly[2::2]
    # 算法逻辑
    for k, v in zip(elist, clist):
        k = int(k)
        if polynomial.get(k) is None:
            polynomial[k] = float(v)
        else:
            polynomial[k] += float(v)

result_list = [(k, polynomial[k])
               for k in sorted(polynomial.keys(), reverse=True)]

# 处理输出
result = []
for e1, e2 in result_list:
    if e2+0.05 > 0 and e2 <= 0:
        continue
    result.append(" %d %0.1f" % (e1, e2))
print(len(result), end='')
print(''.join(result))
