#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>
const int Null = -1;

using namespace std;

struct Node {
  int pos;  // address
  int data;
  int next_pos;

  Node() = default;
  Node(int p, int d, int n) : pos(p), data(d), next_pos(n) {}

  bool operator<(const Node& rhs) { return this->data < rhs.data; }
} g_nodes[100005];

int main() {
  int fst_pos, n, k;
  cin >> fst_pos >> n >> k;
  for (int i = 0; i < n; ++i) {
    int pos, data, next_pos;
    cin >> pos >> data >> next_pos;
    if (next_pos == Null)
      next_pos = 100004;
    g_nodes[pos].pos = pos;
    g_nodes[pos].data = data;
    g_nodes[pos].next_pos = next_pos;
  }

  vector<Node> sorted_nodes;
  for (int it = fst_pos; it != 100004; it = g_nodes[it].next_pos)
    sorted_nodes.push_back(g_nodes[it]);

  int len = sorted_nodes.size();
  for (int i = 0; i + k <= len; i += k) {
    auto it = begin(sorted_nodes) + i;
    auto end = begin(sorted_nodes) + i + k;
    std::reverse(it, end);
  }

  for (int i = 0; i != len - 1; i++)
    printf("%05d %d %05d\n", sorted_nodes[i].pos, sorted_nodes[i].data,
           sorted_nodes[i + 1].pos);
  printf("%05d %d -1", sorted_nodes[len - 1].pos, sorted_nodes[len - 1].data);

  return 0;
}