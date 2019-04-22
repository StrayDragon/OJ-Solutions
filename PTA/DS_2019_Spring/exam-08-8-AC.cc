#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
const int MAXN = 110;
const int INF = 1 << 16;

int graph[MAXN][MAXN];
int indegrees[MAXN] = {0};
int earliest[MAXN] = {0};
int n, m;

int tlsort() {
  queue<int> que;
  for (int i = 0; i < n; i++)
    if (indegrees[i] == 0) que.push(i);

  int cnt = 0;
  while (!que.empty()) {
    int v_i = que.front();
    que.pop();

    cnt++;
    for (int i = 0; i < n; i++) {
      if (graph[v_i][i] != INF) {
        if (earliest[v_i] + graph[v_i][i] > earliest[i])
          earliest[i] = graph[v_i][i] + earliest[v_i];

        if (--indegrees[i] == 0) que.push(i);
      }
    }
  }
  int earliest_time = *max_element(earliest, earliest + n);
  if (cnt == n)
    return earliest_time;
  else
    return -1;
}

int main() {
  // 初始化图
  for (auto& row : graph)
    for (auto& i : row) i = INF;
  // 读入数据
  cin >> n >> m;
  for (int from, to, w, i = 0; i < m; i++) {
    cin >> from >> to >> w;
    // 写入图
    graph[from][to] = w;
    // 计算各顶点入度
    indegrees[to]++;
    // 初始化并茶几
  }

  int result = tlsort();
  if (result == -1)
    cout << "Impossible\n";
  else
    cout << result << '\n';

  return 0;
}
