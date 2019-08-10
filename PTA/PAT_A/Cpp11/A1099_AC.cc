#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define N 110
#define ALL(x) begin(x), end(x)

struct Node {
  int data, lchild, rchild;
} nodes[N];

int n, in[N], cnt = 0;

void in_order(int root_i) {
  if (root_i == -1) return;
  in_order(nodes[root_i].lchild);
  nodes[root_i].data = in[cnt++];
  in_order(nodes[root_i].rchild);
}

void bfs(int root_i) {
  queue<int> q;
  q.push(root_i);
  cnt = 0;
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    cout << nodes[t].data;
    cnt++;
    if (cnt < n) cout << ' ';
    if (nodes[t].lchild != -1) q.push(nodes[t].lchild);
    if (nodes[t].rchild != -1) q.push(nodes[t].rchild);
  }
}

int main() {
  cin >> n;
  for (int lc, rc, i = 0; i < n && cin >> lc >> rc; i++) {
    nodes[i].lchild = lc;
    nodes[i].rchild = rc;
  }

  for (int i = 0; i < n; i++) cin >> in[i];

  std::sort(in, in + n);
  in_order(0);

  bfs(0);
  return 0;
}