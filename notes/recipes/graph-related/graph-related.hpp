#pragma once

#include <bits/stdc++.h>

const int N = 30, INF = 1e9;

using std::cout;
using std::priority_queue;
using std::queue;
using std::vector;

namespace AllOk {

struct Edge {
  int u, v;
  int cost;
} E[N];

namespace bfs {
int father[N];
int init() {
  for (int i = 1; i <= N; i++) father[i] = i;
}
int find(int x) {
  int a = x;
  while (x != father[x]) x = father[x];
  while (a != father[a]) father[std::exchange(a, father[a])] = x;
  return x;
}
}  // namespace bfs

int kruskal(int n, int m) {
  bfs::init();
  int res = 0, edgescnt = 0;
  std::sort(E, E + m, [](Edge& a, Edge& b) { return a.cost < b.cost; });
  for (int i = 0; i < m; i++) {
    int ru = bfs::find(E[i].u);
    int rv = bfs::find(E[i].v);
    if (ru != rv) {
      bfs::father[ru] = rv;
      res += E[i].cost;
      edgescnt++;
      if (edgescnt == n - 1) break;
    }
  }
  if (edgescnt != n - 1) return -1;
  return res;
}

}  // namespace AllOk

namespace AdjListImpl {

vector<int> G[N];
int vis[N];
int n;

void dfs(int s, int depth = -1) {
  vis[s] = true;
  for (auto v : G[s]) {
    if (!vis[v]) dfs(v);  // dfs(v,depth+1);
  }
}

void dfs_main() {
  for (int i = 0; i < n; i++)
    if (!vis[i]) dfs(i);  // dfs(i,1);
}

void bfs(int s) {
  queue<int> q;
  q.push(s);
  vis[s] = true;
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    for (auto u : G[t]) {
      if (!vis[u]) {
        q.push(u);
        vis[u] = true;
      }
    }
  }
}

void bfs_main() {
  for (int i = 0; i < n; i++)
    if (!vis[i]) bfs(i);  // bfs(i,1);
}

int d[N], w[N][N];
void dijkstra(int s) {
  std::fill(d, d + N, INF);
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, min_ = INF;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && d[j] < min_) {
        u = j;
        min_ = d[j];
      }
    }
    if (u == -1) return;
    vis[u] = true;
    for (auto v : G[u]) {
      if (!vis[v] && d[u] + w[u][v] < d[v]) {
        d[v] = d[u] + w[u][v];
      }
    }
  }
}

int prim() {
  std::fill(d, d + N, INF);
  d[0] = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, _ = INF;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && d[j] < _) {
        u = j;
        _ = d[j];
      }
    }
    if (u == -1) return -1;
    vis[u] = true;
    res += d[u];
    for (auto v : G[u]) {
      if (!vis[v] && w[u][v] < d[v]) {
        d[v] = w[u][v];
      }
    }
  }
  return res;
}

int indegree[N];
bool topological_sort() {
  int vertiescnt = 0;
  priority_queue<int> pq; 
  for (int i = 0; i < n; i++)
    if (indegree[i] == 0) pq.push(i);
  while (!pq.empty()) {
    int u = pq.top();
    // cout << u;
    pq.pop();
    for (auto v : G[u]) {
      indegree[v]--;
      if (indegree[v] == 0) pq.push(v);
    }
    // G[u].clear();
    vertiescnt++;
  }
  if (vertiescnt != n) return false;
  return true;
}

}  // namespace AdjListImpl

namespace AdjMatrixImpl {

int G[N][N];
int vis[N];

int n;
void dfs(int s, int depth = -1) {
  vis[s] = true;
  for (int v = 0; v < n; v++) {
    if (!vis[v] && G[s][v] != INF) dfs(v);  // dfs(v,depth+1);
  }
}

void dfs_main() {
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs(i);  // dfs(i,1);
  }
}

void bfs(int s) {
  queue<int> q;
  vis[s] = true;
  q.push(s);

  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int v = 0; v < n; v++) {
      if (!vis[v] && G[t][v] != INF) {
        q.push(v);
        vis[v] = true;
      }
    }
  }
}

void bfs_main() {
  for (int v = 0; v < n; v++) {
    if (!vis[v]) bfs(v);
  }
}

int d[N];
void dijkstra(int s) {
  std::fill(d, d + N, INF);
  d[s] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, min_ = INF;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && d[j] < min_) {
        u = j;
        min_ = d[j];
      }
    }
    if (u == -1) return;
    vis[u] = true;
    for (int v = 0; v < n; v++) {
      if (!vis[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
        d[v] = d[u] + G[u][v];
      }
    }
  }
}

void floyd() {
  for (int k = 0; k < n; k++) {
    for (int v = 0; v < n; v++) {
      for (int u = 0; u < n; u++) {
        if (G[u][k] != INF and G[k][v] != INF) {
          if (G[u][k] + G[k][v] < G[u][v]) {
            G[u][v] = G[u][k] + G[k][v];
          }
        }
      }
    }
  }
}

int prim() {
  std::fill(d, d + N, INF);
  d[0] = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, _ = INF;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && d[j] < _) {
        u = j;
        _ = d[j];
      }
    }
    if (u == -1) return -1;
    vis[u] = true;
    res += d[u];
    for (int v = 0; v < n; v++) {
      if (!vis[v] && G[u][v] != INF && G[u][v] < d[v]) {
        d[v] = G[u][v];
      }
    }
  }
  return res;
}

}  // namespace AdjMatrixImpl
