// ---
// id         : 1002
// title      : A+B for Polynomials
// difficulty : Medium
// score      : 25
// tag        : Simple Simulation
// keyword    : polynomial addition
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <functional>
#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, double, std::greater<int>> items;

  for (int e, k; cin >> k;) {
    for (double c; k != 0 && (cin >> e >> c); --k) {
      items[e] += c;  // 默认初始化为 std::pair{key, 0.0}, 故可直接累加
      if (items[e] == 0) items.erase(e);
    }
  }

  cout << items.size();
  for (auto&& kv : items) printf(" %d %.1lf", kv.first, kv.second);
  return 0;
}