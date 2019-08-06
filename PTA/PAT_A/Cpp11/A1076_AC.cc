// ---
// id         : A1076
// title      : Forwards on Weibo
// difficulty : Hard
// score      : 30
// tag        : Graph
// keyword    : BFS
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define N 1010

struct Node {
  int no, layer;
};
vector<Node> G[N];
bool visited[N];

int bfs(int start, int level) {
  std::fill(visited, visited + N, false);
  int cnt = 0;
  queue<Node> que;
  que.push({start, 0});
  visited[start] = true;
  for (Node t; !que.empty();) {
    t = que.front();
    que.pop();
    int u = t.no;
    for (auto& node : G[u]) {
      node.layer = t.layer + 1;
      if (!visited[node.no] && node.layer <= level) {
        que.push(node);
        visited[node.no] = true;
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  int n, level;
  cin >> n >> level;
  for (int m, i = 1; i <= n && cin >> m; i++)
    for (int v; m-- && cin >> v;) G[v].push_back({i, 0});

  int k;
  cin >> k;
  for (int q; k-- && cin >> q;) {
    int cnt = bfs(q, level);
    cout << cnt << '\n';
  }
  return 0;
}