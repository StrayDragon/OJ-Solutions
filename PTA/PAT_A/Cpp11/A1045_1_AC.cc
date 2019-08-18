// ---
// id         : A1045_1
// title      : Favorite Color Stripe
// difficulty : Hard
// score      : 30
// tag        : TODO
// keyword    : TODO
// status     : AC
// from       : PAT (Advanced Level) Practice
// ---

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ALL(x) begin(x), end(x)
#define UNLIKE -1

int seq[10010], dict[210];

template <typename T>
int LIS(T& seq, int size) {
  static int dp[10010];
  int res = -1;
  for (int i = 0; i < size; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (seq[i] >= seq[j] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
    }
    res = std::max(res, dp[i]);
  }
  return res;
}

int main() {
  std::fill(ALL(dict), UNLIKE);
  int _, m;
  cin >> _ >> m;
  for (int e, i = 0; i < m && cin >> e; i++) dict[e] = i;
  int l, n = 0;
  cin >> l;
  for (int e, i = 0; i < l && cin >> e; i++)
    if (dict[e] != UNLIKE) seq[n++] = dict[e];

  cout << LIS(seq, n);
  return 0;
}