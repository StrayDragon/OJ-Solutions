// ---
// id         : 1087
// title      : All Roads Lead to Rome
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
#include <unordered_map>
#include <vector>

using namespace std;

#define N 210
#define INF 0x3fffffff

int n, k;
unordered_map<string, int> city2i;
unordered_map<int, string> i2city;

int G[N][N], W[N];
bool visited[N];
int d[N], w[N], path_cnt[N], path_v_cnt[N], pre[N];

void fill_all(int* p, int e) { std::fill(p, p + N, e); }
void dijkstra(int s) {
  fill_all(d, INF);
  d[s] = 0;
  w[s] = W[0];
  path_cnt[s] = 1;
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
          w[v] = w[u] + W[v];
          path_cnt[v] = path_cnt[u];
          path_v_cnt[v] = path_v_cnt[u] + 1;
          pre[v] = u;
        } else if (d[u] + G[u][v] == d[v]) {
          path_cnt[v] += path_cnt[u];
          if (w[u] + W[v] > w[v]) {
            w[v] = w[u] + W[v];
            path_v_cnt[v] = path_v_cnt[u] + 1;
            pre[v] = u;
          } else if (w[u] + W[v] == w[v]) {
            double u_avg = 1.0 * (w[u] + W[v]) / (path_v_cnt[u] + 1);
            double v_avg = 1.0 * w[v] / path_v_cnt[v];
            if (u_avg > v_avg) {
              path_v_cnt[v] = path_v_cnt[u] + 1;
              pre[v] = u;
            }
          }
        }
      }
    }
  }
}

void print_path(int v) {
  if (v == 0) {
    cout << i2city[v];
    return;
  }
  print_path(pre[v]);
  cout << "->" << i2city[v];
}

void mapping(string& city, int i) {
  city2i[city] = i;
  i2city[i] = city;
}

int main() {
  string start, c1, c2;
  cin >> n >> k >> start;
  mapping(start, 0);
  for (int i = 1; i <= n - 1; i++) {
    cin >> c1 >> W[i];
    mapping(c1, i);
  }

  std::fill(G[0], G[0] + N * N, INF);
  for (int u, v, i = 0; i < k; i++) {
    cin >> c1 >> c2;
    u = city2i[c1];
    v = city2i[c2];
    cin >> G[u][v];
    G[v][u] = G[u][v];
  }

  dijkstra(0);

  int ed = city2i["ROM"];
  printf("%d %d %d %d\n", path_cnt[ed], d[ed], w[ed], w[ed] / path_v_cnt[ed]);
  print_path(ed);
  return 0;
}