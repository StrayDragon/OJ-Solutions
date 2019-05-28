#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1010;

vector<int> graph[MAXN];
int indegree[MAXN];

int main() {
  int n, m;
  cin >> n >> m;

  for (int v1, v2; m--;) {
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    indegree[v2]++;
  }

  int k, pos = 0;
  cin >> k;
  for (bool is_topsort, is_first = true; k--; pos++) {
    is_topsort = true;
    vector<int> _indegree(indegree, indegree + n + 1);
    for (int v, i = 0; i < n; i++) {
      cin >> v;
      if (_indegree[v] != 0)
        is_topsort = false;
      for (auto it : graph[v])
        _indegree[it]--;
    }
    if (!is_topsort) {
      cout << (is_first ? "" : " ") << pos;
      is_first = false;
    }
  }

  return 0;
}