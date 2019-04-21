#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int n, m;
struct Edge {
  int v1, v2;
  int w;
  Edge(int _1, int _2, int _3) : v1(_1), v2(_2), w(_3) {}
};
vector<Edge> edges;
int ufs_find(vector<int>& ufs, int x) {
  return ufs[x] == x ? x : ufs_find(ufs, ufs[x]);
}

int kruskal() {
  int min_cost = 0, edge_cnt = 0;

  std::sort(begin(edges), end(edges),
            [](const Edge& lhs, const Edge& rhs) { return lhs.w < rhs.w; });

  vector<int> ufs(edges.size() + 3);
  for (int i = 0; i < ufs.size(); ++i)
    ufs[i] = i;

  for (int i = 0; i < edges.size(); ++i) {
    int a = ufs_find(ufs, edges[i].v1);
    int b = ufs_find(ufs, edges[i].v2);
    if (a != b) {
      ufs[a] = b;
      min_cost += edges[i].w;
      edge_cnt++;
      if (edge_cnt == n - 1)
        break;
    }
  }
  if (edge_cnt != n - 1)
    return -1;
  return min_cost;
}

int main() {
  cin >> n >> m;
  for (int v1, v2, w; cin >> v1 >> v2 >> w;)
    edges.push_back(Edge(v1, v2, w));

  auto min_cost = kruskal();
  cout << min_cost << endl;
  return 0;
}