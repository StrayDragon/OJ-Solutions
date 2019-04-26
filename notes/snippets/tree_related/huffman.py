from pprint import PrettyPrinter
from typing import List, Tuple, Dict

debug = PrettyPrinter(indent=4)


class Node(object):
    def __init__(self, value, feq, lchild=None, rchild=None):
        self.value = value
        self.feq = feq
        self.lchild = lchild
        self.rchild = rchild

    def __lt__(self, other):
        return self.feq < other.feq

    def __eq__(self, other):
        if other:
            return self.value == other.value
        else:
            return False

    @classmethod
    def dummy(cls, feq=0, lchild=None, rchild=None):
        return cls('_', feq, lchild, rchild)


def get_wpl(weight_nodes: List[int]) -> int:
    """获取哈弗曼树的WPL(Weighted Path Length).

    Arguments:
        weight_nodes {List[int]} -- 权重结点

    Returns:
        int -- 计算出的WPL值
    """
    from heapq import heapify, heappop, heappush
    wpl: int = 0
    heap: List[int] = weight_nodes[:]
    heapify(heap)
    while len(heap) >= 2:
        min1 = heappop(heap)
        min2 = heappop(heap)
        this_sum = min1 + min2
        heappush(heap, this_sum)
        wpl += this_sum
    return wpl


def huffman_encode(target: str) -> str:

    def convert_to_weight_tuples(targets: str) -> List[Tuple[str, int]]:
        table = {}
        for c in targets:
            if c not in table:
                table[c] = 1
            else:
                table[c] += 1
        result = sorted(list(table.items()), key=lambda k: k[1])
        return result

    def get_huffman_code(char_freqs: List[Tuple[str, int]]) -> Dict[str, str]:
        from heapq import heappush, heappop
        heap = []
        for char, freq in char_freqs:
            heappush(heap, Node(char, freq))
        while len(heap) >= 2:
            left = heappop(heap)
            right = heappop(heap)
            top = Node.dummy(left.feq+right.feq, lchild=left, rchild=right)
            heappush(heap, top)
        result, DUMMY = {}, Node.dummy()

        def __huffman_code_helper(curnode: Node, code: str):
            if curnode == None:
                return
            if curnode != DUMMY:
                # print(curnode.value)
                result[curnode.value] = code
            __huffman_code_helper(curnode.lchild, code+'0')
            __huffman_code_helper(curnode.rchild, code+'1')
        __huffman_code_helper(heap[0], '0')

        return result

    char_freqs = convert_to_weight_tuples(target)
    code_table = get_huffman_code(char_freqs)
    # debug.pprint(code_table)
    coded = (code_table[ch] for ch in target)
    return "".join(coded)


def huffman_decode(huffman_code: str) -> str:
    return ''


def main():
    weight_nodes = [6, 1, 2, 2, 3]
    print(get_wpl.__name__, get_wpl(weight_nodes))
    s = 'AAABBACCCDEEA'
    print(huffman_encode.__name__, huffman_encode(s))


if __name__ == "__main__":
    main()
