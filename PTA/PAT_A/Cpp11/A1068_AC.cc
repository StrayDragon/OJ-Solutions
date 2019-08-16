// ---
// id         : 1068
// title      : Find More Coins
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>

using namespace std;

#define N 10010
#define M 110

int w[N], dp[M];
bool chose[N][N], flag[N];

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i];
  std::sort(w + 1, w + 1 + n, greater<int>());
  for (int i = 1; i <= n; i++) {
    for (int v = m; v >= w[i]; v--) {
      if (dp[v] <= dp[v - w[i]] + w[i]) {
        dp[v] = dp[v - w[i]] + w[i];
        chose[i][v] = true;
      } else {
        chose[i][v] = false;
      }
    }
  }
  if (dp[m] != m)
    cout << "No Solution\n";
  else {
    int cnt = 0;
    for (int k = n, v = m; k >= 0; k--) {
      if (chose[k][v]) {
        flag[k] = true;
        v -= w[k];
        cnt++;
      } else {
        flag[k] = false;
      }
    }
    for (int i = n; i >= 1; i--) {
      if (flag[i]) {
        cout << w[i];
        cnt--;
        if (cnt) cout << ' ';
      }
    }
  }
  return 0;
}