#include "graph-related.hpp"

using namespace std;
using namespace AllOk;

void useKruskal() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> E[i].u >> E[i].v >> E[i].cost;
  }
  int mst_weight = kruskal(n, m);
  cout << mst_weight;
}

void usePrimAdjList() {
  using namespace AdjListImpl;
  std::fill(w[0], w[0] + N * N, INF);
  int n, m;
  cin >> n >> m;
  AdjListImpl::n = n;
  for (int u, v, wt, i = 0; i < m && cin >> u >> v >> wt; i++) {
    G[u].push_back(v);
    G[v].push_back(u);
    w[u][v] = w[v][u] = wt;
  }
  int mst_weight = prim();
  cout << mst_weight;
}

void usePrimAdjMatrix() {
  using namespace AdjMatrixImpl;
  std::fill(G[0], G[0] + N * N, INF);
  int n, m;
  cin >> n >> m;
  AdjMatrixImpl::n = n;
  for (int u, v, wt, i = 0; i < m && cin >> u >> v >> wt; i++) {
    G[u][v] = G[v][u] = wt;
  }
  int mst_weight = prim();
  cout << mst_weight;
}

int main() {
  // usePrimAdjList();
  // usePrimAdjMatrix();
  // useKruskal();
  return 0;
}