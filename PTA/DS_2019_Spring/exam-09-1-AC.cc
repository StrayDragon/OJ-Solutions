#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100010;
int elements[MAXN];
int n;

void input_helper(function<void()> sort_fn) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &elements[i]);

  sort_fn();

  printf("%d", elements[0]);
  for (int i = 1; i < n; i++)
    printf(" %d", elements[i]);
}

void std_sort_solution() {
  std::sort(elements, elements + n);
}

void std_stable_sort_solution() {
  std::stable_sort(elements, elements + n);
}

void std_heap_sort_solution() {
  std::make_heap(elements, elements + n);
  std::sort_heap(elements, elements + n);
}

void std_priority_queue_solution() {
  std::priority_queue<int, vector<int>, std::greater<int>> que(elements,
                                                               elements + n);

  for (int i = 0; !que.empty();) {
    elements[i++] = que.top();
    que.pop();
  }
}

int main() {
  input_helper(std_stable_sort_solution);
  return 0;
}