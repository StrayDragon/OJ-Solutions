from enum import Enum
import operator


class __BinHeap(object):

    def __up_adjust(self, low: int, high: int):
        nodevars = self.__nodevars
        i, j = high, high//2
        while j >= low:
            if self.compare_fn(nodevars[i], nodevars[j]): # 注意此处比较与下滤相反
                nodevars[j], nodevars[i] = nodevars[i], nodevars[j]
                i = j
                j = i // 2
            else:
                break

    def __down_adjust(self, low: int, high: int):
        nodevars = self.__nodevars
        i, j = low, low*2
        while j <= high:
            if j + 1 <= high and self.compare_fn(nodevars[j+1], nodevars[j]):
                j += 1
            if self.compare_fn(nodevars[j], nodevars[i]):
                nodevars[j], nodevars[i] = nodevars[i], nodevars[j]
                i = j
                j = i*2
            else:
                break

    def __init__(self, elems: list, compare_fn=operator.lt):
        self.compare_fn = compare_fn
        self.__nodevars = [len(elems)]
        self.__nodevars.extend(elems)
        n = self.__nodevars[0]
        for i in range(n//2, 0, -1):
            self.__down_adjust(i, n)

    def push(self, nodevar: int):
        self.__nodevars.append(nodevar)
        self.__up_adjust(1, self.size())

    def pop(self):
        v = self.__nodevars.pop()
        if not self.is_empty():
            self.__nodevars[1] = v
            self.__down_adjust(1, self.size())

    def top(self):
        return self.__nodevars[1]

    def size(self) -> int:
        return len(self.__nodevars) - 1

    def is_empty(self):
        return self.size() == 0


# 使用 BinHeap作为实现
PriorityQueue = __BinHeap


if __name__ == "__main__":
    pq = PriorityQueue([2, 3, 1, 4])
    pq.push(6)
    pq.push(5)
    while not pq.is_empty():
        print(pq.top(), end=' ')
        pq.pop()
