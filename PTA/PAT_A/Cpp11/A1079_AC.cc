// ---
// id         : 1079
// title      : Total Sales of Supply Chain
// difficulty : Medium
// score      : 25
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

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

double total = 0;

int max_depth = 0;
void dfs(int root_i, int depth) {
  if (nodes[root_i].children.size() == 0) {
    total += nodes[root_i].weight * p * pow(1 + r, depth);
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
    if (k == 0) {  // 读入 retailer 销售额
      cin >> nodes[i].weight;
    } else {  // 读入 distributors 或 retailers 位置
      for (int j = 0, tmp; j < k; ++j) {
        cin >> tmp;
        nodes[i].children.push_back(tmp);
      }
    }
  }

  dfs(0, 0);
  printf("%.1f\n", total);

  return 0;
}