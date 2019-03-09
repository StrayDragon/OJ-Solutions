from typing import List, Tuple

NULL = -1


def reverse_linked_list(sorted_nodes: List[tuple], k: int) -> List[tuple]:
    size = len(sorted_nodes)
    nodes = []
    if size <= k:
        nodes = sorted_nodes[::-1]
    else:
        remain = size - k
        begin, end = k-1, -1
        while remain > 0:
            for i in range(begin, end, -1):
                nodes.append(sorted_nodes[i])
            begin += k
            end += k
            remain -= k
        cur_len = len(nodes)
        if cur_len < size:
            if remain == 0:
                nodes.extend(sorted_nodes[-1:cur_len-1:-1])
            else:
                nodes.extend(sorted_nodes[cur_len:])
    return nodes


def read_data() -> Tuple[int, List[tuple]]:
    fst_pos, cnt, k = tuple(map(int, input().split()))

    nodes = []
    for _ in range(cnt):
        nodes.append(tuple(map(int, input().split())))

    sorted_nodes = []
    node_itr = fst_pos
    while node_itr != NULL:
        for pos, data, next_pos in nodes:
            if node_itr == pos:
                sorted_nodes.append((pos, data))
                node_itr = next_pos
                break

    return k, sorted_nodes


def print_helper(nodes: List[tuple]):
    for i in range(len(nodes)-1):
        pos, data = nodes[i]
        next_pos, _ = nodes[i+1]
        print("%05d %d %05d" % (pos, data, next_pos))

    pos, data = nodes[-1]
    print("%05d %d %d" % (pos, data, NULL))


def test_extreme():
    with open('exam-02-3-extreme.input', 'a') as f:
        f.writelines("00000 100000 500\n")
        for i in range(100000-1):
            f.writelines("%05d %d %05d\n" % (i, i+1, i+1))
        f.writelines("99999 100000 -1\n")


if __name__ == "__main__":
    k, nodes = read_data()
    result = reverse_linked_list(nodes, k)
    print_helper(result)
