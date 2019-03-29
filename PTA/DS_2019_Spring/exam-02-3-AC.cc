//参考 https://blog.csdn.net/fanfan4569/article/details/52876221
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 100001;  ///最大为五位数的地址

struct node  ///使用顺序表存储data和下一地址next
{
  int data;
  int next;
} node[MAXN];

int List[MAXN];  ///存储可以连接上的顺序表
int main() {
  int First, n, k;
  scanf("%d%d%d", &First, &n, &k);
  int Address, Data, Next;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &Address, &Data, &Next);
    node[Address].data = Data;
    node[Address].next = Next;
  }

  int j = 0;      /// j用来存储能够首尾相连的节点数
  int p = First;  /// p指示当前结点
  while (p != -1) {
    List[j++] = p;
    p = node[p].next;
  }
  int i = 0;
  while (i + k <= j)  ///每k个节点做一次翻转
  {
    reverse(&List[i], &List[i + k]);
    i = i + k;
  }
  for (i = 0; i < j - 1; i++)
    printf("%05d %d %05d\n", List[i], node[List[i]].data, List[i + 1]);
  printf("%05d %d -1\n", List[i], node[List[i]].data);
  return 0;
}