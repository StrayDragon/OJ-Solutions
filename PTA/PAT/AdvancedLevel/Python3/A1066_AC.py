class TreeNode(object):
    def __init__(self, value, height=1, lchild=None, rchild=None):
        self.value = value
        self.height = height
        self.lchild = None
        self.rchild = None

    def __repr__(self):
        return f'TreeNode({self.value})'


class AVLTree(object):
    def __init__(self):
        self.root = None

    def get_height(self, node):
        if isinstance(node, TreeNode):
            return node.height
        return 0

    def insert(self, value):
        def _insert(value, node):
            if not isinstance(node, TreeNode):
                node = TreeNode(value)
            else:
                if value < node.value:
                    node.lchild = _insert(value, node.lchild)
                    node.height = self.__update_height(node)
                    if self.get_balance_factor(node) == 2:
                        if self.get_balance_factor(node.lchild) == 1:
                            node = self.__right_rotation(node)
                        elif self.get_balance_factor(node.lchild) == -1:
                            node.lchild = self.__left_rotation(node.lchild)
                            node = self.__right_rotation(node)
                else:
                    node.rchild = _insert(value, node.rchild)
                    node.height = self.__update_height(node)
                    if self.get_balance_factor(node) == -2:
                        if self.get_balance_factor(node.rchild) == -1:
                            node = self.__left_rotation(node)
                        elif self.get_balance_factor(node.rchild) == 1:
                            node.rchild = self.__right_rotation(node.rchild)
                            node = self.__left_rotation(node)
            return node
        self.root = _insert(value, self.root)

    def __left_rotation(self, node):
        root = node
        new_root = root.rchild
        root.rchild = new_root.lchild
        new_root.lchild = root
        root.height = self.__update_height(root)
        new_root.height = self.__update_height(new_root)
        return new_root

    def __right_rotation(self, node):
        root = node
        new_root = root.lchild
        root.lchild = new_root.rchild
        new_root.rchild = root
        root.height = self.__update_height(root)
        new_root.height = self.__update_height(new_root)
        return new_root

    def get_balance_factor(self, node):
        return self.get_height(node.lchild) - self.get_height(node.rchild)

    def __update_height(self, node):
        return max(self.get_height(node.lchild), self.get_height(node.rchild)) + 1

    def __repr__(self):
        return f'AVLTree({self.root})'


def main():
    _ = int(input())
    nodes = map(int, input().split())
    avl = AVLTree()
    for node in nodes:
        avl.insert(node)
    print(avl.root.value)


if __name__ == "__main__":
    main()
