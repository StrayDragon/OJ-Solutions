#include <cstdio>
#include <cstdlib>
#include <cstring>
void heap_down_adjust(int* heap, int parent) {
  int temp = heap[parent];
  int child = 2 * parent;
  if (child + 1 <= heap[0] && heap[child + 1] < heap[child])
    ++child;
  while (child <= heap[0] && heap[child] < temp) {
    heap[parent] = heap[child];
    parent = child;
    child = 2 * parent;
    if (child + 1 <= heap[0] && heap[child + 1] < heap[child])
      ++child;
  }
  heap[parent] = temp;
}
void make_min_heap(int* heap) {
  for (int i = heap[0] / 2; i > 0; --i)
    heap_down_adjust(heap, i);
}
int heap_pop(int* heap) {
  int minElem = heap[1];
  heap[1] = heap[heap[0]--];
  heap_down_adjust(heap, 1);
  return minElem;
}
void heap_push(int* heap, int weight) {
  heap[++heap[0]] = weight;
  for (int i = heap[0] / 2; i > 0 && heap[i] > weight; i /= 2)
    heap_down_adjust(heap, i);
}
int huffman_get_wpl(int* freq) {
  int heap[100] = {0};
  int size = 0;
  for (int i = 0; i < 256; ++i) {
    if (freq[i]) {
      heap[++size] = freq[i];
    }
  }
  heap[0] = size;
  make_min_heap(heap);
  int wpl = 0;
  for (int i = 1; i < size; ++i) {
    int w1 = heap_pop(heap);
    int w2 = heap_pop(heap);
    wpl += w1 + w2;
    heap_push(heap, w1 + w2);
  }
  return wpl;
}
int is_prefix(char* s1, char* s2) {
  while (s1 && s2 && *s1 == *s2)
    ++s1, ++s2;
  if (*s1 == '\0' || *s2 == '\0')
    return 1;
  else
    return 0;
}
int has_prefix_code(char s[][200], int n) {
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (is_prefix(s[i], s[j]))
        return 1;
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  int freq[256] = {0};
  for (int i = 0; i < n; ++i) {
    char ch;
    int num;
    getchar();
    scanf("%c%d", &ch, &num);
    freq[ch] = num;
  }
  int wpl = huffman_get_wpl(freq);
  int k;
  scanf("%d", &k);
  while (k--) {
    char ch[256];
    char s[256][200];
    int this_wpl = 0;
    for (int i = 0; i < n; ++i) {
      scanf("\n%c %s", &ch[i], s[i]);
      this_wpl += freq[ch[i]] * strlen(s[i]);
    }
    if (this_wpl == wpl && !has_prefix_code(s, n))
      printf("Yes\n");
    else
      printf("No\n");
  }

  return 0;
}
