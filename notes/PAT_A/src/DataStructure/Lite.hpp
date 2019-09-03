#pragma once

#include <cstdlib>

namespace ds {
namespace lite {

/**
 * @brief 栈 (静态实现)
 *
 */
namespace StackFn {

const int MAX_STK_SIZE = 110;
using E = int;

E stk_[MAX_STK_SIZE];
int top_ = -1;
void clear() { top_ = -1; }
int size() { return top_ + 1; }
bool empty() { return top_ == -1 ? true : false; }
void push(E x) { stk_[++top_] = x; }
void pop() { --top_; }
E top() { return stk_[top_]; }

}  // namespace StackFn

/**
 * @brief 队列(静态实现)
 *
 */
namespace QueueFn {

const int MAX_QUE_SIZE = 110;
using E = int;

int que_[MAX_QUE_SIZE];
int front_ = -1, rear_ = -1;
void clear() { front_ = rear_ = -1; }
int size() { return rear_ - front_; }
bool empty() { return front_ == rear_ ? true : false; }
void push(E x) { que_[++rear_] = x; }
void pop() { ++front_; }
int front() { return que_[front_ + 1]; }
int rear() { return que_[rear_]; }

}  // namespace QueueFn

/**
 * @brief 链表 (动态实现)
 * 注: 没有销毁函数,仅适用OJ一次性代码
 *
 */
namespace LinkedListFn {

using E = int;

struct Node {
  E data;
  Node* next;
};

bool empty(Node* head) { return head->next == nullptr; }
E front(Node* head) { return head->next->data; }

Node* init(const E arr[], int len) {
  Node *p, *pre, *head;
  head = (Node*)malloc(sizeof(Node));
  head->next = nullptr;
  pre = head;

  for (int i = 0; i < len; i++) {
    p = (Node*)malloc(sizeof(Node));
    p->data = arr[i], p->next = nullptr;
    pre->next = p, pre = p;
  }
  return head;
}

int count(Node* head, E x) {
  int cnt = 0;
  auto* p = head->next;
  for (; p; p = p->next)
    if (p->data == x) cnt++;
  return cnt;
}

void insert(Node* head, int pos, E x) {
  auto* p = head;
  for (int i = 0; i < pos - 1; i++) {
    p = p->next;
  }
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = x, node->next = p->next;
  p->next = node;
}

void remove(Node* head, E x) {
  auto* p = head->next;
  auto* pre = head;
  while (p) {
    if (p->data == x) {
      pre->next = p->next;
      free(p);
      p = pre->next;
    } else {
      pre = p;
      p = p->next;
    }
  }
}

}  // namespace LinkedListFn

/**
 * @brief 链表 (静态实现)
 *
 */
namespace ArrayListFn {

const int MAX_AL_SIZE = 110;
using E = int;

struct Node {
  E data;
  int next;
} node_[MAX_AL_SIZE];

// 操作具体情况,具体分析

}  // namespace ArrayListFn

/**
 * @brief TODO:并查集
 *
 */
namespace UFSFn {
const int MAX_UFS_SIZE = 10;

/**
 * @brief 即 Set
 *
 */
int ufs_[MAX_UFS_SIZE];
int is_root_[MAX_UFS_SIZE];

void init() {
  for (int i = 0; i < MAX_UFS_SIZE; i++) {
    ufs_[i] = i;
    is_root_[i] = 0;
    // ufs_[i] = -1;
  }
}

/**
 * @brief 即 Find
 *
 * @param x
 * @return int
 */
int find(int x) {
  int a = x;
  while (x != ufs_[x]) x = ufs_[x];
  while (a != ufs_[a]) ufs_[std::exchange(a, ufs_[a])] = x;
  return x;
}

int find_father(int x) {
  while (x != ufs_[x]) {
    x = ufs_[x];
  }
  return x;
}

int find_father_zip(int x) {
  int a = x;

  while (x != ufs_[x]) {
    x = ufs_[x];
  }

  while (a != ufs_[a]) {
    int z = a;
    a = ufs_[a];
    ufs_[z] = x;
  }

  return x;
}

int find_father_zip_recursive(int x) {
  if (x = ufs_[x])
    return x;
  else {
    int f = find_father_recursive(ufs_[x]);
    ufs_[x] = f;
    return f;
  }
}

int find_father_recursive(int x) {
  return (x == ufs_[x]) ? x : find_father_recursive(ufs_[x]);
}

/**
 * @brief 即 Union
 *
 * @param a
 * @param b
 */
void link(int a, int b) {
  int af = find_father(a);
  int bf = find_father(b);
  if (af != bf) ufs_[af] = bf;
}

/**
 * @brief 计算所有集合个数
 *
 * @param n
 * @return int
 */
int count_set(int n) {
  std::fill(is_root_, is_root_ + n, 0);
  for (int i = 0; i < n; i++) is_root_[find(i)] += 1;

  int cnt = 0;
  for (int i = 0; i < n; i++) cnt += is_root_[i];
  return cnt;
}

}  // namespace UFSFn

/**
 * @brief TODO:堆
 *
 */
namespace HeapFn {
const int MAX_HEAP_SIZE = 100;

int heap_[MAX_HEAP_SIZE], n_ = 10;

void down_adjust_(int low, int high) {
  int i = low;
  int j = i * 2;

  while (j <= high) {
    if (j + 1 <= high && heap_[j + 1] > heap_[j]) j = j + 1;

    if (heap_[j] > heap_[i]) {
      std::swap(heap_[j], heap_[i]);
      i = j;
      j = i * 2;
    } else
      break;
  }
}

void create() {
  for (int i = n_ / 2; i >= 1; i--) down_adjust_(i, n_);
}

void delete_top() {
  heap_[1] = heap_[n_--];
  down_adjust_(1, n_);
}

void up_adjust_(int low, int high) {
  int i = high, j = i / 2;
  while (j >= low) {
    if (heap_[j] < heap_[i]) {
      std::swap(heap_[j], heap_[i]);
      i = j;
      j = i / 2;
    } else
      break;
  }
}

void insert(int data) {
  heap_[++n_] = data;
  up_adjust_(1, n_);
}

void sort() {
  create();
  for (int i = n_; i > 1; i--) {
    std::swap(heap_[i], heap_[1]);
    down_adjust_(1, i - 1);
  }
}
}  // namespace HeapFn

}  // namespace lite
}  // namespace ds
