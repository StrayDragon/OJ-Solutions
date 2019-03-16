from math import cos, sin

r1, p1, r2, p2 = map(float, input().split())

a, b = r1 * cos(p1), r1 * sin(p1)
c, d = r2 * cos(p2), r2 * sin(p2)

complex_num = (a*c - b*d, b*c + a*d)

if complex_num[0] + 0.005 >= 0 and complex_num[0] < 0:
    print('0.00', end='')
else:
    print('%.2f' % complex_num[0], end='')

if complex_num[1] >= 0:
    print('+%.2fi' % complex_num[1], end='')
elif complex_num[1] + 0.005 >= 0 and complex_num[1] < 0:
    print('+0.00i', end='')
else:
    print('%.2fi' % complex_num[1], end='')
