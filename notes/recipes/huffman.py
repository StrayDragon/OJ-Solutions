from pprint import PrettyPrinter
from typing import List, Tuple, Dict


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


class _Node(object):
    """特化用于表示Huffman树的结点"""

    def __init__(self, value, feq, lchild=None, rchild=None):
        self.value = value
        self.feq = feq
        self.lchild = lchild
        self.rchild = rchild

    def __lt__(self, other):
        if not self.value.startswith('_') and other.value.startswith('_'):
            return False
        if self.value.startswith('_') and not other.value.startswith('_'):
            return True
        return self.feq < other.feq

    def __eq__(self, other):
        if other:
            return self.value == other.value
        else:
            return False

    @classmethod
    def dummy(cls, feq=0, lchild=None, rchild=None):
        return cls(f'_{feq}', feq, lchild, rchild)


debug = PrettyPrinter(indent=2)


def _level_print(root: _Node):
    """层序遍历并打印结点value

    Arguments:
        root {_Node} -- 根
    """
    from collections import deque
    que = deque([root])
    while len(que) != 0:
        curnode: _Node = que.popleft()
        if curnode:
            print(curnode.value, end=' ')
        if curnode.lchild:
            que.append(curnode.lchild)
        if curnode.rchild:
            que.append(curnode.rchild)
    print()


def _convert_to_weight_tuples(targets: str, *, reverse=False) -> List[Tuple[str, int]]:
    """将指定字符串转换为排序好频率列表

    Arguments:
        targets {str} -- 待编码字符串

    Keyword Arguments:
        reverse {bool} -- 是否反转排序(升序)结果 (default: {False})

    Returns:
        List[Tuple[str, int]] -- [(字符,字符频率)...]
    """
    table = {}
    for c in targets:
        if c not in table:
            table[c] = 1
        else:
            table[c] += 1
    result = sorted(list(table.items()), key=lambda k: k[1], reverse=False)
    return result


def _get_huffman_code(char_freqs: List[Tuple[str, int]]) -> Dict[str, str]:
    """获取字符-字符编码表

    Arguments:
        char_freqs {List[Tuple[str, int]]} -- 字符-字符频率列表

    Returns:
        Dict[str, str] -- 字符-字符编码表
    """
    from heapq import heappush, heappop
    heap = []
    for char, freq in char_freqs:
        heappush(heap, _Node(char, freq))
    while len(heap) >= 2:
        left = heappop(heap)
        right = heappop(heap)
        top = _Node.dummy(left.feq+right.feq, lchild=left, rchild=right)
        # print(left.value, right.value, top.value)
        heappush(heap, top)
    result, DUMMY = {}, _Node.dummy()

    def __huffman_code_helper(curnode: _Node, code: str):
        if curnode == None:
            return
        if curnode != DUMMY:
            # print(curnode.value)
            result[curnode.value] = code
        __huffman_code_helper(curnode.lchild, code+'0')
        __huffman_code_helper(curnode.rchild, code+'1')
    # _level_print(heap[0])
    __huffman_code_helper(heap[0], '')

    return result


# 1 FIXME:一个隐患,若flip=True,则相应的decode会失效
def huffman_encode(target: str, *, flip=False) -> str:
    """对指定字符串进行Huffman编码
    ```
            root
          0/    \\1   # -- 编码 (默认为向左子树编码0,向右子树编码1)
       lchild   rchild
       . . .     . . .
    ```
    Arguments:
        target {str} -- 待编码字符串

    Keyword Arguments:
        flip {bool} --  是否翻转编码串(default: {False}) 
        # 1 FIXME: 此参数有缺陷,若不decode则可用

    Returns:
        str -- 编码后只包含0|1的字符串
    """

    char_freqs = _convert_to_weight_tuples(target)
    # print(char_freqs)
    code_table = _get_huffman_code(char_freqs)
    # debug.pprint(code_table)
    coded = (code_table[ch] for ch in target)
    return "".join(map(lambda i: '0' if i == '1' else '1', coded)) if flip else "".join(coded)


# 1 FIXME:
def huffman_decode(huffman_code: str, code_dict: dict) -> str:
    """对指定Huffman编码(0|1码)解码

    Arguments:
        huffman_code {str} -- Huffman编码后的0|1串
        code_dict {dict} -- 指定串的每个字符到(0|1)编码的映射关系

    Returns:
        str -- 解码结果
    """

    origin_dict = {v: k
                   for k, v in code_dict.items()
                   if not k.startswith('_')}
    # debug.pprint(origin_dict)
    decoded = ""
    t = ''
    for bit in huffman_code:
        t += bit
        if t in origin_dict:
            decoded += origin_dict[t]
            t = ''
        else:
            continue
    return decoded


def main():
    s = 'AAABBACCCDEEA'
    print("original string:\n", s)
    print(f"{huffman_encode.__name__}:\n", huffman_encode(s))
    weight_nodes = [5, 3, 2, 2, 1]
    print(f"{get_wpl.__name__}:\n", get_wpl(weight_nodes))
    print(f"{huffman_decode.__name__}:\n", huffman_decode(huffman_encode(s),
                                                          _get_huffman_code(_convert_to_weight_tuples(s))))


if __name__ == "__main__":
    main()
