from array import array

COUNT_FROM_INDEX_1 = -1

n, _ = map(int, input().split())

heap_buf = array('i', [COUNT_FROM_INDEX_1] + list(map(int, input().split())))

random_indices = list(map(int, input().split()))


def heap_down_adjust(i, last_i):
    j = i * 2  # left child i
    while j <= last_i:
        if j + 1 <= last_i and heap_buf[j + 1] < heap_buf[j]:
            j += 1  # right child i
        if heap_buf[j] < heap_buf[i]:
            heap_buf[j], heap_buf[i] = heap_buf[i], heap_buf[j]
            i = j
            j = i * 2
        else:
            break


def heap_init_adjust():
    i = n // 2
    while i >= 1:
        heap_down_adjust(i, n)
        i -= 1


def heap_insert(root_i, i):
    father_i = i // 2
    while father_i >= root_i:
        if heap_buf[father_i] > heap_buf[i]:
            heap_buf[father_i], heap_buf[i] = heap_buf[i], heap_buf[father_i]
            i = father_i
            father_i //= 2
        else:
            break


def heap_init_adjust2():
    for i in range(1, len(heap_buf)):
        heap_insert(i, n)


# heap_init_adjust()
heap_init_adjust2()

# print(heap_buf)
for i in random_indices:
    while True:
        if i == 1:
            print(heap_buf[i])
            break
        else:
            print(heap_buf[i], '', end='')
        i //= 2
