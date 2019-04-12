#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 16;
const int MAXN = 510;
int n, m, s, d;
struct Weight {
  int dist = INF, cost = INF;
};

vector<vector<Weight>> graph(MAXN, vector<Weight>(MAXN));

int find_min_dist(const vector<int>& dist, const vector<int>& collected) {
  int min_dist = INF, v = -1;
  for (int i = 0; i < n; i++) {
    if (!collected[i] && dist[i] < min_dist) {
      min_dist = dist[i];
      v = i;
    }
  }
  return v;
}

void dijkstra() {
  vector<int> visited(n, false);
  vector<int> path(n, -1);
  vector<int> dist(n, 0);
  vector<int> cost(n, 0);
  for (int i = 0; i < n; i++) {
    dist[i] = graph[s][i].dist;
    cost[i] = graph[s][i].cost;
  }

  dist[s] = 0;
  visited[s] = true;
  while (true) {
    auto v = find_min_dist(dist, visited);
    if (v == -1)
      break;
    visited[v] = true;
    for (int w = 0; w < n; w++) {
      if (!visited[w] && graph[v][w].dist) {
        if (dist[v] + graph[v][w].dist < dist[w]) {
          dist[w] = dist[v] + graph[v][w].dist;
          cost[w] = cost[v] + graph[v][w].cost;
          path[w] = v;
        } else if (dist[v] + graph[v][w].dist == dist[w] &&
                   cost[v] + graph[v][w].cost < cost[w]) {
          cost[w] = cost[v] + graph[v][w].cost;
        }
      }
    }
  }
  cout << dist[d] << " " << cost[d] << endl;
}

int main() {
  cin >> n >> m >> s >> d;

  for (int _ = 0; _ < m; _++) {
    int v1, v2;
    cin >> v1 >> v2;
    cin >> graph[v1][v2].dist >> graph[v1][v2].cost;
    graph[v2][v1].dist = graph[v1][v2].dist;
    graph[v2][v1].cost = graph[v1][v2].cost;
  }

  dijkstra();

  return 0;
}