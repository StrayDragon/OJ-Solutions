// ---
// id         : 1004
// title      : Counting Leaves
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define N 110

vector<int> G[N];
int leaves[N];
int height = 1;

void dfs(int i, int h) {
  height = std::max(h, height);
  if (G[i].empty()) {
    leaves[h]++;
    return;
  }
  for (auto& v : G[i]) dfs(v, h + 1);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int u, k; m-- && cin >> u >> k;)
    for (int v; k-- && cin >> v;) G[u].push_back(v);

  dfs(1, 1);

  std::copy(leaves + 1, leaves + height, ostream_iterator<int>(cout, " "));
  cout << leaves[height];
  return 0;
}