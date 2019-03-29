from typing import List
NULL = -1


class Node(object):
    def __init__(self, d: str, lchild: int, rchild: int):
        self.data = d
        self.lchild, self.rchild = lchild, rchild

    def __repr__(self):
        return f'Node( {self.data}, {self.lchild}, {self.rchild} )'


def retrieve_tree_info():
    n = int(input())
    def is_digit(x): return x in [str(i) for i in range(10)]
    root = NULL
    nodes = []
    used_pos = [False for _ in range(n)]
    for _ in range(n):
        data, lc, rc = input().split()
        if is_digit(lc):
            lc = int(lc)
            used_pos[lc] = True
        else:
            lc = NULL
        if is_digit(rc):
            rc = int(rc)
            used_pos[rc] = True
        else:
            rc = NULL
        nodes.append(Node(data, lc, rc))
    for i, is_used in enumerate(used_pos):
        if not is_used:
            root = i
            break
    return root, nodes


def is_omorphic(r1: int, r2: int) -> bool:
    if r1 == NULL and r2 == NULL:
        return True
    if (r1 == NULL and r2 != NULL) or (r1 != NULL and r2 == NULL):
        return False
    if t1[r1].data != t2[r2].data:
        return False
    if t1[r1].lchild == NULL and t2[r2].lchild == NULL:
        return is_omorphic(t1[r1].rchild, t2[r2].rchild)
    if t1[r1].lchild != NULL and t2[r2].lchild != NULL and t1[t1[r1].lchild].data == t2[t2[r2].lchild].data:
        return is_omorphic(t1[r1].lchild, t2[r2].lchild) and is_omorphic(t1[r1].rchild, t2[r2].rchild)
    else:
        return is_omorphic(t1[r1].lchild, t2[r2].rchild) and is_omorphic(t1[r1].rchild, t2[r2].lchild)


root1, t1 = retrieve_tree_info()
root2, t2 = retrieve_tree_info()

print('Yes'if is_omorphic(root1, root2) else 'No')
