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
} g_nodes[100005];

int main() {
  int fst_pos, n, k;
  cin >> fst_pos >> n >> k;
  for (int i = 0; i < n; ++i) {
    int pos, data, next_pos;
    cin >> pos >> data >> next_pos;
    if (next_pos == Null) next_pos = 100004;
    g_nodes[pos].pos = pos;
    g_nodes[pos].data = data;
    g_nodes[pos].next_pos = next_pos;
  }

  vector<Node> sorted_nodes;
  for (int it = fst_pos; it != 100004; it = g_nodes[it].next_pos)
    sorted_nodes.push_back(g_nodes[it]);

  vector<Node> res;
  int last = 0;
  for (last = k - 1; last < n; last += k)
    for (int i = last; i >= last / k * k; i--) res.push_back(sorted_nodes[i]);

  if (last - k != n)
    for (auto i = last - k + 1; i < n; i++) res.push_back(sorted_nodes[i]);

  for (int i = 0; i != n - 1; i++)
    printf("%05d %d %05d\n", res[i].pos, res[i].data, res[i + 1].pos);
  printf("%05d %d -1\n", res[n - 1].pos, res[n - 1].data);

  return 0;
}