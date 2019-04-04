#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#define ALL(x) begin(x), end(x)
using namespace std;

const int MAXN = 1010;

vector<int> graph[MAXN];
bool visited[MAXN];

int cur_del_vertex_i;
void dfs(int v) {
  if (v == cur_del_vertex_i)
    return;
  visited[v] = true;
  for (int i = 0; i < graph[v].size(); i++) {
    if (!visited[graph[v][i]]) {
      dfs(graph[v][i]);
    }
  }
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }

  for (int query = 0; query < k; query++) {
    cin >> cur_del_vertex_i;
    std::fill(ALL(visited), false);
    int connect = 0;
    for (int i = 1; i <= n; i++) {
      if (i != cur_del_vertex_i && !visited[i]) {
        dfs(i);
        connect++;
      }
    }
    cout << connect - 1 << '\n';
  }

  return 0;
}