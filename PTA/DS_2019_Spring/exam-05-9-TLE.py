from typing import List
from heapq import heapify, heappop, heappush


def get_wpl(weights: List[int]) -> int:
    heap = weights[:]
    heapify(heap)
    size = len(heap)
    wpl = 0

    for i in range(size-1):
        w1 = heappop(heap)
        w2 = heappop(heap)
        wpl += w1+w2
        heappush(heap, w1+w2)
        w1 = w2 = 0

    return wpl


def has_prefix_code(codes: List[str], n: int) -> bool:

    def is_prefix(s1: str, s2: str) -> bool:
        i1, i2 = 0, 0
        while i1 < len(s1) and i2 < len(s2) and s1[i1] == s2[i2]:
            i1 += 1
            i2 += 1
        if i1 == len(s1) or i2 == len(s2):
            return True
        return False

    for i in range(n):
        for j in range(i+1, n):
            if is_prefix(codes[i], codes[j]):
                return True
    return False


def main():
    n = int(input())
    chs_feqs = input().split()
    chs = chs_feqs[0::2]
    feqs = list(map(int, chs_feqs[1::2]))

    feqs_table = {k: v for k, v in zip(chs, feqs)}
    wpl = get_wpl(feqs)

    m = int(input())
    for _ in range(m):
        codes = []
        this_wpl = 0
        for _ in range(n):
            pair = input().split()
            codes.append(pair[1])
            this_wpl += int(feqs_table[pair[0]]) * len(pair[1])
        # Judge this case
        if this_wpl == wpl and not has_prefix_code(codes, n):
            print('Yes')
        else:
            print('No')


main()
