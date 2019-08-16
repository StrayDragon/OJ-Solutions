// ---
// id         : 1097
// title      : Deduplication on a Linked List
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100010;
const int LAST = -1;
struct Node {
  int address, key, next;
} nodes[MAXN];
bool visited[10010];

void print_helper(const vector<Node>& vn) {
  if (vn.empty())
    return;
  int i = 0;
  for (; i < vn.size() - 1; i++) {
    printf("%05d %d %05d\n", vn[i].address, vn[i].key, vn[i + 1].address);
  }
  printf("%05d %d -1\n", vn[i].address, vn[i].key);
}

int main() {
  int start, n;
  cin >> start >> n;

  for (int pos; n--;) {
    cin >> pos;
    nodes[pos].address = pos;
    cin >> nodes[pos].key >> nodes[pos].next;
  }

  vector<Node> valid_nodes, dup_nodes;
  for (int abs_key, i = start;; i = nodes[i].next) {
    abs_key = std::abs(nodes[i].key);
    if (!visited[abs_key]) {
      valid_nodes.push_back(nodes[i]);
      visited[abs_key] = true;
    } else {
      dup_nodes.push_back(nodes[i]);
    }
    if (nodes[i].next == LAST)
      break;
  }

  print_helper(valid_nodes);
  print_helper(dup_nodes);
  return 0;
}