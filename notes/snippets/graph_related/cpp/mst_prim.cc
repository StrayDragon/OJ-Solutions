#include <bits/stdc++.h>
const int MAXV = 1000;
const int INF = 1000000000;

int n, G[MAXV][MAXV];
int d[MAXV];
bool is_visited[MAXV] = {false};

int prim() {
  std::fill(d, d + MAXV, INF);
  d[0] = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int u = -1, MIN = INF;
    for (int j = 0; j < n; j++) {
      if (is_visited[j] == false && d[j] < MIN) {
        u = j;
        MIN = d[j];
      }
    }

    if (u == -1)
      return -1;
    is_visited[u] = true;
    sum += d[u];
    for (int v = 0; v < n; v++) {
      if (is_visited[v] == false && G[u][v] != INF && G[u][v] < d[v])
        d[v] = G[u][v];
    }
  }
  return sum;
}

int main() {
  return 0;
}