#include <algorithm>
#include <iostream>
#include <iterator>

/// O(logn)
void heap_down_adjust(int low, int high);
/// O(n)
void heap_create();
/// O(logn)
void heap_delete_top();
/// O(logn)
void heap_up_adjust(int low, int high);
/// O(logn)
void heap_insert(int data);
/// O(nlogn)
void heap_sort();

const int MAXN = 100;

int heap[MAXN], n = 10;

void heap_down_adjust(int low, int high) {
  int i = low;
  int j = i * 2;

  while (j <= high) {
    if (j + 1 <= high && heap[j + 1] > heap[j])
      j = j + 1;

    if (heap[j] > heap[i]) {
      std::swap(heap[j], heap[i]);
      i = j;
      j = i * 2;
    } else
      break;
  }
}

void heap_create() {
  for (int i = n / 2; i >= 1; i--)
    heap_down_adjust(i, n);
}

void heap_delete_top() {
#ifdef DEBUG
  std::cout << "pop:" << heap[1] << std::endl;
#endif
  heap[1] = heap[n--];
  heap_down_adjust(1, n);
}

void heap_up_adjust(int low, int high) {
  int i = high, j = i / 2;
  while (j >= low) {
    if (heap[j] < heap[i]) {
      std::swap(heap[j], heap[i]);
      i = j;
      j = i / 2;
    } else
      break;
  }
}

void heap_insert(int data) {
  heap[++n] = data;
  heap_up_adjust(1, n);
}

void heap_sort() {
  heap_create();
  for (int i = n; i > 1; i--) {
    std::swap(heap[i], heap[1]);
    heap_down_adjust(1, i - 1);
  }
}

using namespace std;
#define PART(x) begin(x) + 1, begin(x) + n + 1
int main() {
  int actual[MAXN] = {
      -1, 85, 55, 82, 57, 68, 92, 99, 98, 66, 56,
  };
  std::copy(PART(actual), begin(heap) + 1);
  std::copy(PART(actual), ostream_iterator<int>(cout, " ")), cout << endl;
  heap_sort();
  std::copy(PART(heap), ostream_iterator<int>(cout, " ")), cout << endl;
  return 0;
}