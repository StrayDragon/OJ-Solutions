// ---
// id         : 1020
// title      : Tree Traversals
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cstdio>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int v;
  TreeNode* lchild;
  TreeNode* rchild;
};
std::function<TreeNode*(int, int, int, int)> create_tree;
int main() {
  int n;
  scanf("%d", &n);
  // 读入后序遍历
  vector<int> postnodes(n);
  int tmp;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    postnodes[i] = tmp;
  }
  // 读入中序遍历
  vector<int> innodes(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    innodes[i] = tmp;
  }

  create_tree = [&postnodes, &innodes](int post_l, int post_r, int in_l,
                                       int in_r) -> TreeNode* {
    if (post_l > post_r)
      return nullptr;

    TreeNode* root = new TreeNode();
    root->v = postnodes[post_r];

    int k;
    for (k = in_l; k <= in_r; k++)
      if (innodes[k] == postnodes[post_r])
        break;

    int left_cnt = k - in_l;
    root->lchild = create_tree(post_l, post_l + left_cnt - 1, in_l, k - 1);
    root->rchild = create_tree(post_l + left_cnt, post_r - 1, k + 1, in_r);
    return root;
  };
  TreeNode* root = create_tree(0, n - 1, 0, n - 1);

  auto bfs = [&root, &n]() {
    int cnt = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      printf("%d", node->v);

      cnt++;
      if (cnt < n)
        putchar(' ');
      if (node->lchild != nullptr)
        q.push(node->lchild);
      if (node->rchild != nullptr)
        q.push(node->rchild);
    }
  };
  bfs();
  return 0;
}