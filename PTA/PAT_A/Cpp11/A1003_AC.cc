// ---
// id         : 1003
// title      : Emergency
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>

using namespace std;

#define INF 1234567890
#define N 505

int n, m, c1, c2, graph[N][N], weights[N], d[N], w[N], cnt[N];
bool visited[N] = {false};

void dijkstra(int start) {
  std::fill(d, d + N, INF);
  std::fill(cnt, cnt + N, 0);
  std::fill(w, w + N, 0);
  d[start] = 0;
  w[start] = weights[start];
  cnt[start] = 1;

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
      if (!visited[v] && graph[u][v] != INF) {
        if (d[u] + graph[u][v] < d[v]) {
          d[v] = d[u] + graph[u][v];
          w[v] = w[u] + weights[v];
          cnt[v] = cnt[u];
        } else if (d[u] + graph[u][v] == d[v]) {
          if (w[u] + weights[v] > w[v]) {
            w[v] = w[u] + weights[v];
          }
          cnt[v] += cnt[u];
        }
      }
    }
  }
}

int main() {
  cin >> n >> m >> c1 >> c2;
  for (int i = 0; i < n; ++i) {
    cin >> weights[i];
  }

  std::fill(graph[0], graph[0] + N * N, INF);
  for (int u, v; cin >> u >> v;) {
    cin >> graph[u][v];
    graph[v][u] = graph[u][v];
  }

  dijkstra(c1);

  cout << cnt[c2] << " " << w[c2];
  return 0;
}