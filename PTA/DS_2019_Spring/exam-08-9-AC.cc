#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAXN = 110;
const int INF = 1 << 16;

vector<vector<int>> graph(MAXN, vector<int>(MAXN, INF));
vector<int> indegrees(MAXN, 0);
vector<int> earliest(MAXN, 0);
vector<int> latest(MAXN, 0);

int main() {
  int n, m;
  cin >> n >> m;
  for (int from, to, w, i = 0; i < m; i++) {
    cin >> from >> to >> w;
    graph[from][to] = w;
    indegrees[to]++;
  }

  queue<int> que;
  for (int i = 1; i <= n; ++i)
    if (indegrees[i] == 0)
      que.push(i);

  int cnt = 0;
  for (int v_i; !que.empty();) {
    v_i = que.front();
    que.pop();
    cnt++;
    for (int i = 1; i <= n; i++) {
      if (graph[v_i][i] != INF) {
        if (earliest[v_i] + graph[v_i][i] > earliest[i])
          earliest[i] = earliest[v_i] + graph[v_i][i];
        if (--indegrees[i] == 0)
          que.push(i);
      }
    }
  }
  int idx;
  auto get_max = [&idx, n](const vector<int>& v) {
    int max = 0;
    for (int i = 1; i <= n; i++) {
      if (max < v[i]) {
        max = v[i];
        idx = i;
      }
    }
    return max;
  };
  int ect = get_max(earliest);

  if (cnt != n) {
    cout << "0\n";
  } else {
    cout << ect << '\n';
    queue<int> que;
    vector<int> outdegrees(MAXN, 0);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (graph[i][j] != INF)
          outdegrees[i]++;
    for (int i = 1; i <= n; i++)
      if (outdegrees[i] == 0)
        que.push(i);
    for (int i = 1; i <= n; i++) {
      latest[i] = INF;
    }
    latest[idx] = ect;
    for (int v_i; !que.empty();) {
      v_i = que.front();
      que.pop();
      for (int i = 1; i <= n; i++) {
        if (graph[i][v_i] != INF) {
          if (latest[v_i] - graph[i][v_i] <= latest[i]) {
            latest[i] = latest[v_i] - graph[i][v_i];
            graph[i][v_i] = latest[v_i] - earliest[i] - graph[i][v_i];
          }
          if (--outdegrees[i] == 0)
            que.push(i);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = n; j >= 1; j--) {
        if (graph[i][j] == 0)
          cout << i << "->" << j << '\n';
      }
    }
  }

  return 0;
}