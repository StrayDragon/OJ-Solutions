#include <iostream>
#include <queue>

using namespace std;
struct Node {
  int address, key, next;
} nodes[100010];

int main() {
  int n, start;
  cin >> n >> start;

  auto cmp = [](Node& lhs, Node& rhs) { return lhs.key > rhs.key; };
  priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

  for (int pos, i = 0; i < n; i++) {
    cin >> pos;
    nodes[pos].address = pos;
    cin >> nodes[pos].key >> nodes[pos].next;
  }
  
  int i;
  for (i = start; nodes[i].next != -1; i = nodes[i].next)
    pq.push(nodes[i]);
  pq.push(nodes[i]);

  cout << pq.size() << " " << pq.top().address << '\n';
  for (bool is_first = true; !pq.empty(); pq.pop()) {
    if (pq.size() == 1) {
      if (is_first) {
        printf("%05d %d -1", pq.top().address, pq.top().key);
      } else {
        printf("%05d\n%05d %d -1", pq.top().address, pq.top().address,
               pq.top().key);
      }
    } else {
      if (is_first) {
        printf("%05d %d ", pq.top().address, pq.top().key);
        is_first = false;
      } else {
        printf("%05d\n%05d %d ", pq.top().address, pq.top().address,
               pq.top().key);
      }
    }
  }

  return 0;
}