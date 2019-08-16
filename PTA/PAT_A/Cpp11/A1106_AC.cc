// ---
// id         : 1106
// title      : Lowest Price in Supply Chain
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

#define N 100010
#define INF 0x3fffffff

vector<int> G[N];
int n, cnt = 0;
double p, r, lowest_price = INF;

void dfs(int i, int depth) {
  if (G[i].size() == 0) {
    double price = p * std::pow(1 + r, depth);
    if (price < lowest_price) {
      lowest_price = price;
      cnt = 1;
    } else if (price == lowest_price) {
      cnt++;
    }
    return;
  }
  for (auto& v : G[i]) dfs(v, depth + 1);
}

int main() {
  cin >> n >> p >> r;
  r /= 100;
  for (int k, i = 0; i < n; i++) {
    cin >> k;
    if (k != 0) {
      for (int v; k-- && cin >> v;) G[i].push_back(v);
    }
  }

  dfs(0, 0);
  printf("%.4f %d", lowest_price, cnt);
  return 0;
}