// ---
// id         : 1064
// title      : Complete Binary Search Tree
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

int n;
int idx = 0;
vector<int> nodekeys;
vector<int> nodevars(1010);
void in_order(int root) {
  if (root > n) return;
  in_order(root * 2);
  nodevars[root] = nodekeys[idx];
  idx++;
  in_order(root * 2 + 1);
}

int main() {
  cin >> n;
  for (int key; cin >> key;) nodekeys.push_back(key);

  std::sort(ALL(nodekeys));
  in_order(1);

  cout << nodevars[1];
  for (int i = 2; i < n + 1; i++) cout << " " << nodevars[i];

  return 0;
}
