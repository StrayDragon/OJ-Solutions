#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

const int MAXN = 15;
using namespace std;

vector<int> adj_list[MAXN];
bool visited[MAXN];
int n, e;

void dfs(int v) {
  visited[v] = true;
  cout << v << " ";
  for (auto i : adj_list[v])
    if (!visited[i])
      dfs(i);
}

void bfs(int v) {
  if (!visited[v]) {
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      cout << cur << " ";
      visited[cur] = true;
      for (auto i : adj_list[cur]) {
        if (!visited[i]) {
          q.push(i);
          visited[i] = true;
        }
      }
    }
  }
}

void pprint(function<void(int)> fn) {
  std::fill(begin(visited), end(visited), false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      cout << "{ ";
      fn(i);
      cout << "}\n";
    }
  }
}

int main() {
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    adj_list[v1].push_back(v2);
    adj_list[v2].push_back(v1);
  }
  for_each(begin(adj_list), end(adj_list),
           [](vector<int>& v) { sort(begin(v), end(v)); });
  pprint(dfs);
  pprint(bfs);
  return 0;
}