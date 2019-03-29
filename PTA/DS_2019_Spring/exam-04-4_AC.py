class BST(object):
    def __init__(self, amount: int, *, nodevars):
        self.nodevars = [None for _ in range(2 ** amount)]

        def li(root_i):
            return root_i * 2

        def ri(root_i):
            return root_i * 2 + 1

        def add(v, node_i):
            if self.nodevars[node_i] is None:
                self.nodevars[node_i] = v
                return
            if v < self.nodevars[node_i]:
                add(v, li(node_i))
            elif v > self.nodevars[node_i]:
                add(v, ri(node_i))
            else:
                return

        for nodevar in nodevars:
            add(nodevar, 1)

    def __eq__(self, other):
        for lhs, rhs in zip(self.nodevars, other.nodevars):
            if lhs != rhs:
                return False
        return True


def main():
    while True:
        info = tuple(map(int, input().split()))
        if len(info) == 2:
            n, l = info
            origin_tree = BST(n, nodevars=map(int, input().split()))
            for _ in range(l):
                test_tree = BST(n, nodevars=map(int, input().split()))
                print('Yes' if origin_tree == test_tree else 'No')
        else:
            break


if __name__ == "__main__":
    main()
    # t1 = BST(4, nodevars=[3, 1, 4, 2])
    # t2 = BST(4, nodevars=[3, 4, 1, 2])
    # t3 = BST(4, nodevars=[3, 2, 4, 1])
    # print(t1 == t2)
    # print(t1 == t3)
