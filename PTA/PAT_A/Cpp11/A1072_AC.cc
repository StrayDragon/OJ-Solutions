// ---
// id         : 1072
// title      : Gas Station
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define N 1080
#define INF 0x3fffffff

int n, m, k, ds;

int get_no(string& s) {
  if (s[0] == 'G') {
    s.erase(s.begin());
    return n + stoi(s);
  }
  return stoi(s);
}

int G[N][N], d[N];
bool visited[N];

void dijkstra(int s) {
  std::fill(visited, visited + N, false);
  std::fill(d, d + N, INF);
  d[s] = 0;
  for (int i = 0; i < n + m; i++) {
    int u = -1, min_ = INF;
    for (int j = 1; j <= n + m; j++) {
      if (!visited[j] && d[j] < min_) {
        u = j;
        min_ = d[j];
      }
    }
    if (u == -1) return;
    visited[u] = true;
    for (int v = 1; v <= n + m; v++) {
      if (!visited[v] && G[u][v] != INF) {
        if (d[u] + G[u][v] < d[v]) {
          d[v] = d[u] + G[u][v];
        }
      }
    }
  }
}

int main() {
  std::fill(G[0], G[0] + N * N, INF);

  cin >> n >> m >> k >> ds;
  for (int u, v, w, i = 0; i < k; i++) {
    string u_str, v_str;
    cin >> u_str >> v_str >> w;
    u = get_no(u_str);
    v = get_no(v_str);
    G[u][v] = G[v][u] = w;
  }

  double min_avg_dist = INF, min_dist = -1;
  int target_no = -1;
  for (int i = n + 1; i <= n + m; i++) {
    double dist = INF, avg_dist = 0;
    dijkstra(i);
    for (int j = 1; j <= n; j++) {
      if (d[j] > ds) {
        dist = -1;
        break;
      }
      if (d[j] < dist) dist = d[j];
      avg_dist += 1.0 * d[j] / n;
    }
    if (dist == -1) continue;
    if (dist > min_dist) {
      target_no = i;
      min_dist = dist;
      min_avg_dist = avg_dist;
    } else if (dist == min_dist && avg_dist < min_avg_dist) {
      target_no = i;
      min_avg_dist = avg_dist;
    }
  }

  if (target_no == -1) {
    puts("No Solution");
  } else {
    printf("G%d\n", target_no - n);
    printf("%.1f %.1f\n", min_dist, min_avg_dist);
  }
  return 0;
}