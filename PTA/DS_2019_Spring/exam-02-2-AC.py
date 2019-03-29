from typing import List


def caculate_plus(poly1: List[tuple], poly2: List[tuple]) -> List[tuple]:
    if len(poly1) == 0:
        return poly2[:]
    if len(poly2) == 0:
        return poly1[:]
    plus_result = []
    i, j = 0, 0
    while i < len(poly1) and j < len(poly2):
        if poly1[i][1] == poly2[j][1]:
            c = poly1[i][0] + poly2[j][0]
            if c != 0:
                plus_result.append((c, poly1[i][1]))
            i += 1
            j += 1
        elif poly1[i][1] < poly2[j][1]:
            c, e = poly2[j]
            plus_result.append((c, e))
            j += 1
        else:
            c, e = poly1[i]
            plus_result.append((c, e))
            i += 1

    if i < len(poly1):
        for c, e in poly1[i:]:
            plus_result.append((c, e))

    if j < len(poly2):
        for c, e in poly2[j:]:
            plus_result.append((c, e))

    return plus_result


def calculate_multi(poly1: List[tuple], poly2: List[tuple]) -> List[tuple]:
    multi_result = []
    for c1, e1 in poly1:
        tmp = []
        for c2, e2 in poly2:
            c = c1 * c2
            e = e1 + e2
            tmp.append((c, e))
        multi_result = caculate_plus(multi_result, tmp)
    return multi_result


def read_data():
    this_line = list(map(lambda x: int(x), input().split()))
    if this_line[0] != 0:
        return this_line[1:]
    else:
        return []


def make_items(elems: list):
    if elems:
        yield elems[0], elems[1]
    if elems[2:]:
        yield from make_items(elems[2:])


def print_helper(elems: list):
    if elems:
        elems.sort(key=lambda t: t[1], reverse=True)
        print(elems[0][0], elems[0][1], end='')
        for c, e in elems[1:]:
            print(" %d %d" % (c, e), end='')
    else:
        print("0 0", end='')
    print()


if __name__ == "__main__":
    # 处理输入 & 格式化输入
    first_line = read_data()
    second_line = read_data()

    p1 = list(make_items(first_line))
    p2 = list(make_items(second_line))

    # 处理逻辑 & 格式化输出
    print_helper(calculate_multi(p1, p2))
    print_helper(caculate_plus(p1, p2))
