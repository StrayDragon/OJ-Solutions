#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

const int Null = -1;
struct TreeNode {
  int left_i = Null;
  int right_i = Null;
};

std::function<void(int)> revert_bst;
std::function<void(int, int)> inorder;
using namespace std;
int main() {
  int n;
  cin >> n;

  vector<int> is_root(n, 1);
  vector<TreeNode> tree_nodes(n);
  for (int i = 0; i < n; i++) {
    char tmp;
    cin >> tmp;
    if (tmp != '-') {
      int node_i = tmp - '0';
      tree_nodes[i].left_i = node_i;
      is_root[node_i] = 0;
    }
    cin >> tmp;
    if (tmp != '-') {
      int node_i = tmp - '0';
      tree_nodes[i].right_i = node_i;
      is_root[node_i] = 0;
    }
  }

  int root_i = 0;
  for (int i = 0; i < n; i++) {
    if (is_root[i]) {
      root_i = i;
      break;
    }
  }

  int cnt = 0;
  auto print_helper = [&tree_nodes, &cnt, &n](int nodevar) {
    cout << nodevar;
    cnt++;
    if (cnt < n)
      cout << ' ';
    else
      cout << '\n';
  };

  auto bfs = [&tree_nodes](int root_i, int n) {
    queue<int> q;
    q.push(root_i);
    int cnt = 0;
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      cout << i;
      cnt++;
      if (cnt < n)
        cout << ' ';
      else
        cout << '\n';
      if (tree_nodes[i].left_i != Null)
        q.push(tree_nodes[i].left_i);
      if (tree_nodes[i].right_i != Null)
        q.push(tree_nodes[i].right_i);
    }
  };

  inorder = [&tree_nodes, &print_helper](int root_i, int n) {
    if (root_i == Null)
      return;
    inorder(tree_nodes[root_i].left_i, n);
    print_helper(root_i);
    inorder(tree_nodes[root_i].right_i, n);
  };

  revert_bst = [&tree_nodes](int root_i) {
    if (root_i == Null)
      return;
    revert_bst(tree_nodes[root_i].left_i);
    revert_bst(tree_nodes[root_i].right_i);
    swap(tree_nodes[root_i].left_i, tree_nodes[root_i].right_i);
  };

  revert_bst(root_i);
  bfs(root_i, n);
  inorder(root_i, n);
  return 0;
}