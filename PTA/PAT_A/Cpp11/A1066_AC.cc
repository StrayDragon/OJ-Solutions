#include <iostream>

struct node_t {
  int data;
  int height;
  node_t* lchild;
  node_t* rchild;
};

node_t* new_node(int data) {
  node_t* node = new node_t;
  node->data = data;
  node->height = 1;
  node->lchild = node->rchild = nullptr;
  return node;
}

int get_height(node_t* root) {
  if (root == nullptr)
    return 0;
  return root->height;
}

int get_balance_factor(node_t* root) {
  return get_height(root->lchild) - get_height(root->rchild);
}

void update_height(node_t* root) {
  int lchild_height = get_height(root->lchild);
  int rchild_height = get_height(root->rchild);
  root->height =
      1 + (lchild_height > rchild_height ? lchild_height : rchild_height);
}

void left_rotation(node_t*& root) {
  node_t* tmp = root->rchild;
  root->rchild = tmp->lchild;
  tmp->lchild = root;
  update_height(root);
  update_height(tmp);
  root = tmp;
}

void right_rotation(node_t*& root) {
  node_t* tmp = root->lchild;
  root->lchild = tmp->rchild;
  tmp->rchild = root;
  update_height(root);
  update_height(tmp);
  root = tmp;
}

void insert(node_t*& root, int data) {
  if (root == nullptr) {
    root = new_node(data);
    return;
  }
  if (data < root->data) {
    insert(root->lchild, data);
    update_height(root);
    if (get_balance_factor(root) == 2) {
      if (get_balance_factor(root->lchild) == 1) {
        right_rotation(root);
      } else {
        left_rotation(root->lchild);
        right_rotation(root);
      }
    }
  } else {
    insert(root->rchild, data);
    update_height(root);
    if (get_balance_factor(root) == -2) {
      if (get_balance_factor(root->rchild) == -1) {
        left_rotation(root);
      } else {
        right_rotation(root->rchild);
        left_rotation(root);
      }
    }
  }
}
using namespace std;

int main() {
  node_t* root = nullptr;
  int n, v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v;
    insert(root, v);
  }
  cout << root->data << endl;
  return 0;
}