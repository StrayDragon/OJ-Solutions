#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define N 510
#define INF 0x3fffffff

int n, m, st, ed;

int G[N][N], C[N][N], d[N], c[N], pre[N];
bool visited[N];

void dijkstra(int s) {
  std::fill(d, d + N, INF);
  std::fill(c, c + N, INF);
  d[s] = c[s] = 0;
  for (int i = 0; i < n; i++) pre[i] = i;
  for (int i = 0; i < n; i++) {
    int u = -1, min_ = INF;
    for (int j = 0; j < n; j++) {
      if (!visited[j] && d[j] < min_) {
        u = j;
        min_ = d[j];
      }
    }
    if (u == -1) return;
    visited[u] = true;
    for (int v = 0; v < n; v++) {
      if (!visited[v] && G[u][v] != INF) {
        if (d[u] + G[u][v] < d[v]) {
          d[v] = d[u] + G[u][v];
          c[v] = c[u] + C[u][v];
          pre[v] = u;
        } else if (d[u] + G[u][v] == d[v]) {
          if (c[u] + C[u][v] < c[v]) {
            c[v] = c[u] + C[u][v];
            pre[v] = u;
          }
        }
      }
    }
  }
}

vector<int> path;
void dfs(int v) {
  if (v == st) {
    path.push_back(v);
    return;
  }
  dfs(pre[v]);
  path.push_back(v);
}

int main() {
  std::fill(G[0], G[0] + N * N, INF);

  cin >> n >> m >> st >> ed;
  for (int u, v, dist, cost; m-- && cin >> u >> v >> dist >> cost;) {
    G[v][u] = G[u][v] = dist;
    C[v][u] = C[u][v] = cost;
  }

  dijkstra(st);
  dfs(ed);

  for (auto& i : path) cout << i << ' ';
  cout << d[ed] << ' ' << c[ed];
  return 0;
}