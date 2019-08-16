// ---
// id         : 1155
// title      : Heap Paths
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, nodes[1010];
vector<int> nodes_path;

void dfs(int root_i) {
  if (root_i * 2 > n && root_i * 2 + 1 > n) {
    if (root_i <= n) {
      for (int i = 0; i < nodes_path.size(); i++)
        cout << nodes_path[i] << (i != nodes_path.size() - 1 ? " " : "\n");
    }
  } else {
    nodes_path.push_back(nodes[root_i * 2 + 1]);
    dfs(root_i * 2 + 1);
    nodes_path.pop_back();

    nodes_path.push_back(nodes[root_i * 2]);
    dfs(root_i * 2);
    nodes_path.pop_back();
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> nodes[i];

  nodes_path.push_back(nodes[1]);
  dfs(1);

  bool is_min = true, is_max = true;
  for (int i = 2; i <= n; i++) {
    if (nodes[i / 2] > nodes[i]) is_min = false;
    if (nodes[i / 2] < nodes[i]) is_max = false;
  }
  cout << (is_min ? "Min" : (is_max ? "Max" : "Not")) << " Heap\n";

  return 0;
}