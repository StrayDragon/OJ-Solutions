// ---
// id         : 1043
// title      : Is It a Binary Search Tree
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct TreeNode {
  using Ptr = shared_ptr<TreeNode>;
  int data;
  Ptr lchild, rchild;

  TreeNode() = default;
  TreeNode(int d) : data(d) {}
};

void insert(TreeNode::Ptr& root, int data) {
  if (root == nullptr) {
    root = make_shared<TreeNode>(data);
    return;
  }
  if (data < root->data)
    insert(root->lchild, data);
  else
    insert(root->rchild, data);
}

void pre_order(const TreeNode::Ptr& root, vector<int>& result) {
  if (root == nullptr)
    return;
  result.push_back(root->data);
  pre_order(root->lchild, result);
  pre_order(root->rchild, result);
}

void pre_order_mirror(const TreeNode::Ptr& root, vector<int>& result) {
  if (root == nullptr)
    return;
  result.push_back(root->data);
  pre_order_mirror(root->rchild, result);
  pre_order_mirror(root->lchild, result);
}

void post_order(const TreeNode::Ptr& root, vector<int>& result) {
  if (root == nullptr)
    return;
  post_order(root->lchild, result);
  post_order(root->rchild, result);
  result.push_back(root->data);
}

void post_order_mirror(const TreeNode::Ptr& root, vector<int>& result) {
  if (root == nullptr)
    return;
  post_order_mirror(root->rchild, result);
  post_order_mirror(root->lchild, result);
  result.push_back(root->data);
}

vector<int> source, pre, pre_m, post, post_m;

int main() {
  TreeNode::Ptr root;
  int n;
  cin >> n;
  for (int i = 0, data; i < n; i++) {
    cin >> data;
    source.push_back(data);
    insert(root, data);
  }
  pre_order(root, pre);
  pre_order_mirror(root, pre_m);
  post_order(root, post);
  post_order_mirror(root, post_m);
  if (source == pre) {
    cout << "YES\n";
    for (int i = 0; i < post.size(); i++) {
      cout << post[i];
      if (i < post.size() - 1)
        cout << " ";
    }
  } else if (source == pre_m) {
    cout << "YES\n";
    for (int i = 0; i < post_m.size(); i++) {
      cout << post_m[i];
      if (i < post_m.size() - 1)
        cout << " ";
    }
  } else {
    cout << "NO\n";
  }

  return 0;
}