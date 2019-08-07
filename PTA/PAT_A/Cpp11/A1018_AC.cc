#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define N 510
#define INF 0x3fffffff
int cmax, n, sp, m;

int G[N][N], weight[N];
bool visited[N];

int d[N], min_need = INF, min_remain = INF;
vector<int> pre[N], tmp_path, path;

void dijkstra(int v) {
  std::fill(d, d + N, INF);
  d[v] = 0;
  for (int i = 0; i <= n; i++) {
    int u = -1, min_ = INF;
    for (int j = 0; j <= n; j++) {
      if (!visited[j] && d[j] < min_) {
        u = j;
        min_ = d[j];
      }
    }
    if (u == -1) return;
    visited[u] = true;
    for (int v = 0; v <= n; v++) {
      if (!visited[v] && G[u][v] != INF) {
        if (d[u] + G[u][v] < d[v]) {
          d[v] = d[u] + G[u][v];
          pre[v].clear();
          pre[v].push_back(u);
        } else if (d[u] + G[u][v] == d[v]) {
          pre[v].push_back(u);
        }
      }
    }
  }
}

void dfs(int v) {
  if (v == 0) {
    tmp_path.push_back(v);
    int need = 0, remain = 0;
    for (int i = tmp_path.size() - 1; i >= 0; --i) {
      int no = tmp_path[i];
      if (weight[no] > 0) {
        remain += weight[no];
      } else {
        if (remain > abs(weight[no])) {
          remain -= abs(weight[no]);
        } else {
          need += abs(weight[no]) - remain;
          remain = 0;
        }
      }
    }
    if (need < min_need) {
      min_need = need;
      min_remain = remain;
      path = tmp_path;
    } else if (need == min_need && remain < min_remain) {
      min_remain = remain;
      path = tmp_path;
    }
    tmp_path.pop_back();
    return;
  }
  tmp_path.push_back(v);
  for (auto vi : pre[v]) dfs(vi);
  tmp_path.pop_back();
}

int main() {
  std::fill(G[0], G[0] + N * N, INF);

  cin >> cmax >> n >> sp >> m;
  for (int i = 1; i <= n && cin >> weight[i]; i++) weight[i] -= cmax / 2;
  for (int u, v, w; m-- && cin >> u >> v >> w;) G[v][u] = G[u][v] = w;

  dijkstra(0);
  dfs(sp);

  cout << min_need << " ";
  for (int i = path.size() - 1; i >= 0; --i) {
    cout << path[i];
    if (i > 0) cout << "->";
  }
  cout << " " << min_remain;
  return 0;
}