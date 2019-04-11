#include <iostream>
#include <vector>

using namespace std;

#define INF 10001

using Graph = vector<vector<int>>;

Graph createGraph(int n, int m) {
  Graph graph(n, vector<int>(n, INF));
  while (m--) {
    int a, b, weight;
    cin >> a >> b >> weight;
    graph[a - 1][b - 1] = weight;
    graph[b - 1][a - 1] = weight;
  }
  return graph;
}

Graph floyd(Graph& graph) {
  Graph dist(graph);
  int n = graph.size();

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (k != i || i != j)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

int findMaxDist(int vertex, Graph& dist) {
  int max = 0;
  for (int i = 0; i < dist[vertex].size(); ++i)
    if (i != vertex)
      max = std::max(max, dist[vertex][i]);
  return max;
}

int main() {
  int n, m;
  cin >> n >> m;
  auto graph = createGraph(n, m);
  auto D = floyd(graph);

  int animal = 0, min = INF;
  for (int i = 0; i < n; ++i) {
    auto dist = findMaxDist(i, D);
    if (dist >= INF) {
      cout << 0 << endl;
      return 0;
    }
    if (min > dist) {
      animal = i + 1;  
      min = dist;
    }
  }
  cout << animal << " " << min << endl;

  return 0;
}