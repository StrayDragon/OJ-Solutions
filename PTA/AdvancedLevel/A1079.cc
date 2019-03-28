#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;

struct TreeNode {
  int weight;
  vector<int> children;
} nodes[MAXN];

int n;
double p, r;

double price, total;  // TODO:见P298

int max_depth = 0;
void dfs(int root_i, int depth) {
  if (nodes[root_i].children.size() == 0) {
    if (depth > max_depth) {
      max_depth = depth;
      // cnt_depthest = 1;
    } else if (depth == max_depth) {
      // cnt_depthest++;
    }
    return;
  }
  for (int i = 0; i < nodes[root_i].children.size(); i++)
    dfs(nodes[root_i].children[i], depth + 1);
}
int main() {
  cin >> n >> p >> r;
  r /= 100;
  for (int i = 0; i < n; i++) {
    double k;
    cin >> k;
    if (k == 0) {
      cin >> nodes[i].weight;
    } else {
      for (int j = 0, tmp; j < k; ++j) {
        cin >> tmp;
        nodes[i].children.push_back(tmp);
      }
    }
  }

  dfs(0, 0);
  printf("%.1f\n", price * total);

  return 0;
}