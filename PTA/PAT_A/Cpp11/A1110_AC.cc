// ---
// id         : 1110
// title      : Complete Binary Tree
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int no, lchild, rchild;
} nodes[25];

bool visited[25];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string l, r;
    cin >> l >> r;
    nodes[i].lchild = (l[0] != '-') ? std::stoi(l) : -1;
    nodes[i].rchild = (r[0] != '-') ? std::stoi(r) : -1;
    nodes[i].no = i;
    visited[nodes[i].lchild] = visited[nodes[i].rchild] = true;
  }

  int root = std::distance(begin(visited), find(visited, visited + n, false));

  vector<int> inorders;
  queue<int> que;
  que.push(root);
  for (int i, remain = n; remain && !que.empty();) {
    i = que.front();
    inorders.push_back(i);
    if (i != -1) {
      que.push(nodes[i].lchild);
      que.push(nodes[i].rchild);
      remain--;
    }
    que.pop();
  }

  if (inorders.size() == n)
    cout << "YES " << inorders.back();
  else
    cout << "NO " << root;

  return 0;
}