// ---
// id         : 1094
// title      : The Largest Generation
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 110;
vector<int> nodes[MAXN];
int table[MAXN] = {0};

void dfs(int index, int level) {
  table[level]++;
  for (int i = 0; i < nodes[index].size(); i++)
    dfs(nodes[index][i], level + 1);
}

int main() {
  int n, m, parent, k, child;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> parent >> k;
    for (int j = 0; j < k; j++) {
      cin >> child;
      nodes[parent].push_back(child);
    }
  }

  dfs(1, 1);
  int max_level = -1, max_value = 0;
  for (int i = 1; i < MAXN; i++) {
    if (table[i] > max_value) {
      max_value = table[i];
      max_level = i;
    }
  }

  cout << max_value << " " << max_level << '\n';
  return 0;
}