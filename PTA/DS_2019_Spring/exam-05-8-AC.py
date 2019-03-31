def _find(elems: list, x: int) -> int:
    if elems[x] < 0:
        return x
    elems[x] = _find(elems, elems[x])
    return elems[x]


def _union(elems: list, root1: int, root2: int):
    if elems[root2] < elems[root1]:
        elems[root2] += elems[root1]
        elems[root1] = root2
    else:
        elems[root1] += elems[root2]
        elems[root2] = root1


def connect_vertices(s, v1, v2):
    root1 = _find(s, v1-1)
    root2 = _find(s, v2-1)
    if root1 != root2:
        _union(s, root1, root2)


def check_vertices(s, v1, v2):
    root1 = _find(s, v1-1)
    root2 = _find(s, v2-1)
    if root1 == root2:
        print('yes')
    else:
        print('no')


def check_components(s, n):
    cnt = 0
    for i in range(n):
        if s[i] < 0:
            cnt += 1
    if cnt == 1:
        print('The network is connected.')
    else:
        print('There are %d components.' % cnt)

    pass


def main():
    n = int(input())
    s = [-1 for _ in range(n)]

    import sys
    for line in sys.stdin:
        args = line.split()
        if args[0] == 'S':
            check_components(s, n)
            break

        v1, v2 = map(int, args[1:])
        if args[0] == 'C':
            check_vertices(s, v1, v2)
        elif args[0] == 'I':
            connect_vertices(s, v1, v2)
            pass


main()
