#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 110

struct Node {
  int w;
  vector<int> children;
} nodes[MAXN];

int n, m, s;
int path[MAXN];

void dfs(int idx, int cnt, int sum) {
  if (sum > s) return;
  if (sum == s) {
    if (nodes[idx].children.size() != 0) return;
    for (int i = 0; i < cnt; i++) {
      cout << nodes[path[i]].w;
      if (i < cnt - 1)
        cout << " ";
      else
        cout << '\n';
    }
  }
  for (int i = 0; i < nodes[idx].children.size(); i++) {
    int child = nodes[idx].children[i];
    path[cnt] = child;
    dfs(child, cnt + 1, sum + nodes[child].w);
  }
}

int main() {
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++) cin >> nodes[i].w;

  for (int id, k, child, i = 0; i < m; i++) {
    cin >> id >> k;
    for (int j = 0; j < k; j++) {
      cin >> child;
      nodes[id].children.push_back(child);
    }
    std::sort(nodes[id].children.begin(), nodes[id].children.end(),
              [](int lhs, int rhs) { return nodes[lhs].w > nodes[rhs].w; });
  }

  path[0] = 0;
  dfs(0, 1, nodes[0].w);
  return 0;
}