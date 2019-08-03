#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100010

vector<int> graph[MAXN];
bool is_root[MAXN];

int ufs[MAXN];
void ufs_init(int n) {
  for (int i = 1; i <= n; i++) ufs[i] = i;
}
int ufs_find(int x) {
  int t = x;
  while (x != ufs[x]) x = ufs[x];
  while (t != ufs[t]) ufs[exchange(t, ufs[t])] = x;
  return x;
}
void ufs_union(int x, int y) {
  int rx = ufs_find(x);
  int ry = ufs_find(y);
  if (rx != ry) ufs[rx] = ry;
}

int get_components(int n) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) is_root[ufs_find(i)] = true;
  for (int i = 1; i <= n; i++) cnt += is_root[i];
  return cnt;
}

int max_height = 0;
vector<int> tmp, result;
void dfs(int u, int h, int pre) {
  if (h > max_height) {
    tmp.clear();
    tmp.push_back(u);
    max_height = h;
  } else if (h == max_height) {
    tmp.push_back(u);
  }
  for (int i = 0; i < graph[u].size(); i++) {
    if (graph[u][i] == pre) continue;
    dfs(graph[u][i], h + 1, u);
  }
}

int main() {
  int n;
  cin >> n;
  ufs_init(n);
  for (int u, v, n_ = n; n_-- && cin >> u >> v;) {
    graph[u].push_back(v);
    graph[v].push_back(u);
    ufs_union(u, v);
  }

  int cnt = get_components(n);
  if (cnt != 1) {
    cout << "Error: " << cnt << " components\n";
  } else {
    dfs(1, 1, -1);
    result = tmp;
    dfs(result[0], 1, -1);
    for (auto&& e : tmp) result.push_back(e);
    std::sort(result.begin(), result.end());
    cout << result[0] << '\n';
    for (int i = 1; i < result.size(); i++)
      if (result[i] != result[i - 1]) cout << result[i] << '\n';
  }
  return 0;
}