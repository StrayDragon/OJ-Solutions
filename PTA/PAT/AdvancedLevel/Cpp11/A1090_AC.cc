#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> nodes[MAXN];
int n;
double p, r;

int max_depth = 0, cnt_depthest = 0;

void dfs(int root_i, int depth) {
  if (nodes[root_i].size() == 0) {
    if (depth > max_depth) {
      max_depth = depth;
      cnt_depthest = 1;
    } else if (depth == max_depth) {
      cnt_depthest++;
    }
    return;
  }
  for (int i = 0; i < nodes[root_i].size(); i++)
    dfs(nodes[root_i][i], depth + 1);
}

int main() {
  cin >> n >> p >> r;
  r /= 100;

  int root;
  for (int i = 0, father; i < n; i++) {
    cin >> father;
    if (father != -1)
      nodes[father].push_back(i);
    else
      root = i;
  }
  dfs(root, 0);
  printf("%.2f %d\n", p * pow(1 + r, max_depth), cnt_depthest);

  return 0;
}