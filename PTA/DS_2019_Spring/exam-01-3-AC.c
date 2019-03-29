#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
  ElementType Data[MAXSIZE];
  Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main() {
  List L;
  ElementType X;
  Position P;

  L = ReadInput();
  scanf("%d", &X);
  P = BinarySearch(L, X);
  printf("%d\n", P);

  return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch(List L, ElementType X) {
  if (L->Last == 1 && L->Data[1] != X) return NotFound;
  if (L->Data[1] == X) return 1;
  if (L->Data[L->Last] == X) return L->Last;
  Position mid = -1, bound1 = 1, bound2 = L->Last;

  Position res = NotFound;
  while (bound1 < bound2) {
    if (mid == (bound1 + bound2 + 1) / 2) break;
    mid = (bound1 + bound2 + 1) / 2;
    if (L->Data[mid] == X) {
      res = mid;
      break;
    } else if (L->Data[mid] < X) {
      bound1 = mid;
    } else {
      bound2 = mid;
    }
  }

  return res;
}