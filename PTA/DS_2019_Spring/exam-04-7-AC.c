#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
  ElementType Data;
  BinTree Left;
  BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT); /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main() {
  BinTree BST, MinP, MaxP, Tmp;
  ElementType X;
  int N, i;

  BST = NULL;
  scanf("%d", &N);  //读取结点的个数
  for (i = 0; i < N; i++) {
    scanf("%d", &X);
    BST = Insert(BST, X);  //累计插入N个元素
  }
  printf("Preorder:");
  PreorderTraversal(BST);
  printf("\n");
  MinP = FindMin(BST);  //查找树中最小元素位置
  MaxP = FindMax(BST);  //查找树中最大元素位置
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &X);
    Tmp = Find(BST, X);  //返回树中指定元素的位置
    if (Tmp == NULL)
      printf("%d is not found\n", X);
    else {
      printf("%d is found\n", Tmp->Data);
      if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
      if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
    }
  }
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &X);
    BST = Delete(BST, X);  //删除N个指定元素的结点
  }
  printf("Inorder:");
  InorderTraversal(BST);
  printf("\n");

  return 0;
}
BinTree Insert(BinTree BST, ElementType X) {
  if (BST == NULL) {
    BST = (struct TNode *)malloc(sizeof(struct TNode));
    BST->Data = X;
    BST->Left = BST->Right = NULL;
    return BST;
  }
  if (X < BST->Data) BST->Left = Insert(BST->Left, X);
  if (X > BST->Data) BST->Right = Insert(BST->Right, X);
  return BST;
}

BinTree Delete(BinTree BST, ElementType X) {
  Position Tmp;
  if (!BST)
    printf("Not Found\n");
  else {
    if (X < BST->Data)
      BST->Left = Delete(BST->Left, X);
    else if (X > BST->Data)
      BST->Right = Delete(BST->Right, X);
    else {
      if (BST->Left && BST->Right) {
        Tmp = FindMin(BST->Right);
        BST->Data = Tmp->Data;
        BST->Right = Delete(BST->Right, BST->Data);
      } else {
        Tmp = BST;
        if (!BST->Left)
          BST = BST->Right;
        else if (!BST->Right)
          BST = BST->Left;
        free(Tmp);
      }
    }
  }
  return BST;
}

Position Find(BinTree BST, ElementType X) {
  if (BST == NULL) return NULL;
  if (BST->Data == X) return BST;
  if (BST->Data > X) return Find(BST->Left, X);
  if (BST->Data < X) return Find(BST->Right, X);
}

Position FindMin(BinTree BST) {
  if (!BST) return NULL;
  if (BST->Left)
    return FindMin(BST->Left);
  else
    return BST;
}

Position FindMax(BinTree BST) {
  if (!BST) return NULL;
  if (BST->Right)
    return FindMax(BST->Right);
  else
    return BST;
}

void PreorderTraversal(BinTree BT) {
  return;
} /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT) {
  return;
} /* 中序遍历，由裁判实现，细节不表 */
