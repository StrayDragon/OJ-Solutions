// ---
// id         : 1009
// title      : Product of Polynomials
// difficulty : Medium
// score      : 25
// tag        : Simple Simulation
// keyword    : polynomial multiplication
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

// 黑魔法  (੭•̀ω•́)੭ ̸*✩~
#define E first
#define C second

pair<int, double> polyitems[1010];

double results[2001];
int main() {
  int n1;
  cin >> n1;
  for (int i = 0; i < n1; i++) cin >> polyitems[i].E >> polyitems[i].C;
  int n2;
  cin >> n2;
  for (int e, i = 0; i < n2; i++) {
    double c;
    cin >> e >> c;
    for (int j = 0; j < n1; j++) {
      results[e + polyitems[j].E] += c * polyitems[j].C;
    }
  }

  /* 计算非零系数的项数 */
  int cnt = 0;
  for (int i = 0; i <= 2000; i++) {
    if (results[i] != 0) cnt++;
  }

  cout << cnt;
  for (int i = 2000; i >= 0; i--) {
    if (results[i] != 0)
      // cout << " " << i << " " << std::fixed << std::setprecision(1)
      //      << results[i];
      printf(" %d %.1f", i, results[i]);
  }
}