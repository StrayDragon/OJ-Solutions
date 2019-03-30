#include <cstdio>
#include <cstdlib>

using namespace std;

const int MIN_DATA = -0xFFFF;
typedef struct HeapStruct *MinHeap;
typedef int ElementType;
MinHeap create(int max_size);
MinHeap create_by_array(int mode, ElementType *data, int length);
bool is_empty(MinHeap h);
bool is_full(MinHeap h);
void insert(MinHeap h, ElementType item);

ElementType *retrive_data_arr(MinHeap h);

struct HeapStruct {
  ElementType *data;
  int size;
  int capacity;
};

int n, m;
int *tmp_arr, *wait_to_show_path_arr;
int *level_of_tree_arr;

void read_data() {
  scanf("%d%d", &n, &m);
  tmp_arr = (int *)malloc(sizeof(int) * n);
  wait_to_show_path_arr = (int *)malloc(sizeof(int) * m);
  for (int i = 0; i < n; i++) scanf("%d", &tmp_arr[i]);
  for (int i = 0; i < m; i++) scanf("%d", &wait_to_show_path_arr[i]);
}

void build_min_heap_and_parse_to_arr() {
  MinHeap mh = create_by_array(1, tmp_arr, n);
  level_of_tree_arr = retrive_data_arr(mh);
}

void show_path(int *level_of_tree, int length, int index) {
  for (int i = index; i != 0; i /= 2) {
    printf("%d", level_of_tree[i]);
    if (i / 2 != 0) putchar(' ');
  }
  putchar('\n');
}

#define N_M_LIMIT_CONDITION(x) (((x) > 0) && ((x) <= 1000))
#define DATA_LIMIT_CONDITION(x) (((x) >= -10000) && ((x) <= 10000))

int main(int argc, char const *argv[]) {
  read_data();
  if (N_M_LIMIT_CONDITION(n) && N_M_LIMIT_CONDITION(m)) {
    build_min_heap_and_parse_to_arr();
    for (int i = 0; i < m; i++)
      show_path(level_of_tree_arr, m, wait_to_show_path_arr[i]);
  }
  return 0;
}

MinHeap create(int length) {
  MinHeap h = (MinHeap)malloc(sizeof(struct HeapStruct));
  h->data = (ElementType *)malloc((length + 1) * sizeof(ElementType));
  h->size = 0;
  h->capacity = length;
  h->data[0] = MIN_DATA;  //哨兵
  return h;
}

static void create_mod_1_nlogn(MinHeap h, ElementType *data, int length) {
  for (int i = 0; i < length; i++) insert(h, data[i]);
}

static void _upFloat(MinHeap h, int i) {
  ElementType sub_heap_root_data = h->data[i];
  int child, parent;
  for (parent = i; parent * 2 <= h->size; parent = child) {
    child = parent * 2;    //找到左儿子
    if ((child != h->size) /*判断右儿子是否存在*/
        && (h->data[child] > h->data[child + 1]))
      child++;  // child现在是两者中的最小者
    if (sub_heap_root_data <= h->data[child])
      break;  //此时找到了合适位置:child值
    else      //上浮节点持有的更小的元素
      h->data[parent] = h->data[child];
  }
  h->data[parent] = sub_heap_root_data;
}

static void _buildHeap(MinHeap h) {
  for (int i = h->size / 2; i > 0; i--) _upFloat(h, i);
}

static void create_mod_2_n(MinHeap h, ElementType *data, int length) {
  for (int i = 1; i <= length; i++) h->data[i] = data[i - 1];
  h->size = length;
  _buildHeap(h);
}

MinHeap create_by_array(int mode, ElementType *data, int length) {
  MinHeap h = create(length);

  if (mode == 1) {
    create_mod_1_nlogn(h, data, length);
  } else {
    create_mod_2_n(h, data, length);
  }

  return h;
}

bool is_empty(MinHeap h) { return h->size == 0; }

bool is_full(MinHeap h) { return h->size == h->capacity; }

void insert(MinHeap h, ElementType item) {
  if (is_full(h)) {
    printf("最小堆已满\n");
    return;
  }
  int i = ++h->size;
  for (; h->data[i / 2] > item; i /= 2) {
    h->data[i] = h->data[i / 2];
  }
  h->data[i] = item;
}

ElementType delete_min(MinHeap h) {
  if (is_empty(h)) {
    printf("最小堆已空\n");
    return MIN_DATA;
  }
  ElementType min_item = h->data[1];
  ElementType tmp = h->data[h->size--];
  int parent, child;

  for (parent = 1; parent * 2 <= h->size; parent = child) {
    child = parent * 2;    //找到左儿子
    if ((child != h->size) /*判断右儿子是否存在*/
        && (h->data[child] > h->data[child + 1]))
      child++;  // child现在是两者中的最小者
    if (tmp <= h->data[child])
      break;  //此时找到了合适位置:child值
    else      //上浮节点持有的更小的元素
      h->data[parent] = h->data[child];
  }
  h->data[parent] = tmp;
  return min_item;
}

ElementType *retrive_data_arr(MinHeap h) { return h->data; }
