#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>

#include <queue>
#include <vector>

using namespace std;
const int MAXN = 10010;
int n, m;
vector<int> adj_list[MAXN];
bool visited[MAXN];

int bfs(int v) {
  // https://www.geeksforgeeks.org/level-node-tree-source-node-using-bfs/
  std::fill(begin(visited), end(visited), false);
  vector<int> level(n + 1, -1);
  queue<int> q;
  q.push(v);
  visited[v] = true;
  level[v] = 0;
  int cnt = 0;

  if (adj_list[v].empty())
    return cnt + 1;

  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (int i = 0; i < adj_list[v].size(); i++) {
      int t = adj_list[v][i];
      if (!visited[t]) {
        q.push(t);
        level[t] = level[v] + 1;
        visited[t] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (level[i] <= 6 && level[i] != -1)
      cnt++;
  }

  return cnt;
}

int main() {
  cin >> n >> m;
  int v1, v2;
  for (int i = 0; i < m; i++) {
    cin >> v1 >> v2;
    adj_list[v1].push_back(v2);
    adj_list[v2].push_back(v1);
  }
  for (int i = 1; i <= n; i++) {
    int cnt = bfs(i);
    printf("%d: %.2f%%\n", i, double(cnt) / n * 100);
  }

  return 0;
}