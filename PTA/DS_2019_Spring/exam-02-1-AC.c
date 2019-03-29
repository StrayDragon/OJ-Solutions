#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
  ElementType Data;
  PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main() {
  List L1, L2, L;
  L1 = Read();
  L2 = Read();
  L = Merge(L1, L2);
  Print(L);
  Print(L1);
  Print(L2);
  return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2) {
  List node1 = L1->Next;
  List node2 = L2->Next;
  L1->Next = L2->Next = NULL;
  List res = (List)malloc(sizeof(struct Node));

  /*先声明一下,才能使用帮助函数*/
  List MergeHelper(List n1, List n2);
  res->Next = MergeHelper(node1, node2);
  return res;
}

List MergeHelper(List n1, List n2) {
  if (n1 == NULL)
    return n2;
  if (n2 == NULL)
    return n1;
  if (n1->Data <= n2->Data) {
    n1->Next = MergeHelper(n1->Next, n2);
    return n1;
  } else {
    n2->Next = MergeHelper(n1, n2->Next);
    return n2;
  }
}