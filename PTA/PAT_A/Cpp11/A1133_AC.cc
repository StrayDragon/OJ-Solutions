// ---
// id         : 1133
// title      : Splitting A Linked List
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int addr, data, next;
} nodes[100010];

int main() {
  int first, n, k;
  cin >> first >> n >> k;
  for (int addr; n-- && cin >> addr;) {
    nodes[addr].addr = addr;
    cin >> nodes[addr].data >> nodes[addr].next;
  }

  vector<Node> leftnodes, midnodes, rightnodes;
  for (int i = first;; i = nodes[i].next) {
    if (nodes[i].data < 0)
      leftnodes.push_back(nodes[i]);
    else if (0 <= nodes[i].data && nodes[i].data <= k)
      midnodes.push_back(nodes[i]);
    else
      rightnodes.push_back(nodes[i]);
    if (nodes[i].next == -1) break;
  }

  vector<Node> allnodes(leftnodes.begin(), leftnodes.end());
  allnodes.insert(allnodes.end(), midnodes.begin(), midnodes.end());
  allnodes.insert(allnodes.end(), rightnodes.begin(), rightnodes.end());

  for (int i = 0; i < allnodes.size() - 1; i++)
    printf("%05d %d %05d\n", allnodes[i].addr, allnodes[i].data,
           allnodes[i + 1].addr);
  printf("%05d %d -1\n", allnodes[allnodes.size() - 1].addr,
         allnodes[allnodes.size() - 1].data);
  return 0;
}